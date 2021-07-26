class Solution {
public:
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minPushBox(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int box[2], player[2], target[2];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'S') {
                    player[0] = i;
                    player[1] = j;
                } else if (grid[i][j] == 'T') {
                    target[0] = i;
                    target[1] = j;
                } else if (grid[i][j] == 'B') {
                    box[0] = i;
                    box[1] = j;
                }
            }
        }
        unordered_map<int, int> dis;
        queue<int> moves;
        int start = encode(box[0], box[1], player[0], player[1]), res = INT_MAX;
        dis[start] = 0;
        moves.push(start);
        while (!moves.empty()) {                     
            int key = moves.front();
            moves.pop();
            if (dis[key] >= res) continue;
            vector<int> pos = decode(key);            
            int bX = pos[0], bY = pos[1], pX = pos[2], pY = pos[3];
            if (bX == target[0] && bY == target[1]) {
                res = min(res, dis[key]);
                continue;
            }            
            for (int i = 0; i < 4; i++) {
                int pNX = pos[2] + directions[i][0], pNY = pos[3] + directions[i][1];
                if (pNX < 0 || pNX >= m || pNY < 0 || pNY >= n || grid[pNX][pNY] == '#') continue;
                if (pNX == bX && pNY == bY) {
                    int bNX = bX + directions[i][0], bNY = bY + directions[i][1];
                    if (bNX < 0 || bNX >= m || bNY < 0 || bNY >= n || grid[bNX][bNY] == '#') continue;           
                    int nextKey = encode(bNX, bNY, pNX, pNY);
                    if (dis.find(nextKey) != dis.end() && dis[nextKey] <= dis[key] + 1) continue;
                    dis[nextKey] = dis[key] + 1;
                    moves.push(nextKey);
                } else {
                    int nextKey = encode(bX, bY, pNX, pNY);
                    if (dis.find(nextKey) != dis.end() && dis[nextKey] <= dis[key]) continue;
                    dis[nextKey] = dis[key];
                    moves.push(nextKey);
                }                
            }
        }
        return res == INT_MAX ? -1 : res;        
    }
    
    int encode(int bx, int by, int sx, int sy) {
        return (bx << 24) | (by << 16) | (sx << 8) | sy;
    }
    
    vector<int> decode(int key) {        
        return {(key >> 24) & 0xff, (key >> 16) & 0xff, (key >> 8) & 0xff, key & 0xff};
    }
};