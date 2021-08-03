class Solution {
public:
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size(), maxHeight = 0;        
        vector<vector<int>> res(m, vector<int>(n, 0));
        queue<pair<int, int>> queue;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    queue.push({i, j});
                }
            }
        }
        bfs(isWater, res, queue, m, n);
        return res;
    }
    
    void bfs(vector<vector<int>>& matrix, vector<vector<int>>& res, queue<pair<int, int>>& queue, int m, int n) {        
        while (!queue.empty()) {
            int row = queue.front().first, col = queue.front().second;                        
            queue.pop();           
            for (int i = 0; i < 4; i++) {
                int newRow = row + directions[i][0], newCol = col + directions[i][1];
                if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || matrix[newRow][newCol] > 0) continue;                        
                matrix[newRow][newCol] = 1;                
                res[newRow][newCol] = res[row][col] + 1;                
                queue.push({newRow, newCol});                
            }            
        }        
    }
};

class Solution {
public:
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size(), maxHeight = 0;        
        vector<vector<int>> res(m, vector<int>(n, -1));
        queue<pair<int, int>> queue;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    res[i][j] = 0;
                    queue.push({i, j});
                }
            }
        }
                
         while (!queue.empty()) {
            int row = queue.front().first, col = queue.front().second;                        
            queue.pop();           
            for (int i = 0; i < 4; i++) {
                int newRow = row + directions[i][0], newCol = col + directions[i][1];
                if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || res[newRow][newCol] != -1) continue;                                        
                res[newRow][newCol] = res[row][col] + 1;                
                queue.push({newRow, newCol});                
            }            
        }            
        return res;
    }
    
};

class Solution {
public:
    int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int, int>> cells;
        int m = isWater.size(), n = isWater[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 0) {
                    isWater[i][j] = -1;
                } else {
                    isWater[i][j] = 0;
                    cells.push({i, j});
                }
            }
        }
        while (!cells.empty()) {
            int row = cells.front().first, col = cells.front().second;
            cells.pop();
            for (int i = 0; i < 4; i++) {
                int newRow = row + directions[i][0], newCol = col + directions[i][1];
                if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || isWater[newRow][newCol] >= 0) {
                    continue;
                }
                isWater[newRow][newCol] = isWater[row][col] + 1;
                cells.push({newRow, newCol});
            }
        }
        return isWater;
    }
};