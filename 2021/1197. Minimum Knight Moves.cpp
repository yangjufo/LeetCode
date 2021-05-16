class Solution {
public:
    int directions[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
    int minKnightMoves(int x, int y) {
        vector<vector<bool>> visited(601, vector<bool>(601, false));        
        queue<pair<int, int>> pos;
        pos.push({0, 0});
        visited[300][300] = true;
        int step = -1;
        while (!pos.empty()) {
            int size = pos.size();
            step++;
            for (int i = 0; i < size; i++) {
                int cX = pos.front().first, cY = pos.front().second;
                pos.pop();
                if (cX == x && cY == y) return step;
                for (int j = 0; j < 8; j++) {
                    int nX = cX + directions[j][0], nY = cY + directions[j][1];
                    if (abs(nX) + abs(nY) <= 300 && !visited[nX + 300][nY + 300]) {
                        visited[nX + 300][nY + 300] = true;
                        pos.push({nX, nY});
                    }
                }
            }
        }
        return step;
    }
};