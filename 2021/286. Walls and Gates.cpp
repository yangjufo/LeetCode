class Solution {
public:
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = rooms[0].size();        
        queue<pair<int, int>> steps;        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    steps.push({i, j});
                }
            }            
        }
        int level = -1;        
        while (!steps.empty()) {
            level++;
            int size = steps.size();
            for (int i = 0; i < size; i++) {
                int row = steps.front().first, col = steps.front().second;
                steps.pop();
                for (int d = 0; d < 4; d++) {
                    int newRow = row + directions[d][0], newCol = col + directions[d][1];
                    if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || rooms[newRow][newCol] != INT_MAX) {
                        continue;
                    }
                    rooms[newRow][newCol] = level + 1;
                    steps.push({newRow, newCol});
                }
            }
        }        
    }
};