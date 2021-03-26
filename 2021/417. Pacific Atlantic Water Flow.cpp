class Solution {
public:
    int directions[4][2] ={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = m == 0 ? 0 : matrix[0].size();
        vector<vector<int>> ans;        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            bfs(matrix, m, n, i, 0, pacific);
            bfs(matrix, m, n, i, n - 1, atlantic);
        }
        
        for (int j = 0; j < n; j++) {
            bfs(matrix, m, n, 0, j, pacific);
            bfs(matrix, m, n, m - 1, j, atlantic);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        
        return ans;
    }
    
    void bfs(vector<vector<int>>& matrix, int m, int n, int x, int y, vector<vector<bool>>& visited) {
        if (visited[x][y]) return;
        queue<int*> nodes;
        nodes.push(new int[2]{x, y});
        while (!nodes.empty()) {
            int* curr = nodes.front();
            nodes.pop();
            visited[curr[0]][curr[1]] = true;
            for (int* dir : directions) {
                int a = curr[0] + dir[0], b = curr[1] + dir[1];
                if (a < 0 || a >= m || b < 0 || b >= n || visited[a][b] || matrix[a][b] < matrix[x][y])
                    continue;
                bfs(matrix, m, n, a, b, visited);
            }
        }        
    }
};

class Solution {
public:
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = (m == 0) ? 0 : matrix[0].size();
        if (m == 0 || n == 0) return {};
        vector<vector<int>> pacific(m, vector<int>(n, 0)), atlantic(m, vector<int>(n, 0));
        queue<pair<int, int>> pacificQueue, atlanticQueue;
        for (int i = 0; i < m; i++) {
            pacificQueue.push({i, 0});
            pacific[i][0] = 1;
            atlanticQueue.push({i, n - 1});
            atlantic[i][n - 1] = 1;
        }
        for (int j = 0; j < n; j++) {
            if (j != 0) {
                pacificQueue.push({0, j});
                pacific[0][j] = 1;
            }
            if (j != n - 1) {
                atlanticQueue.push({m - 1, j});
                atlantic[m - 1][j] = 1;
            }            
        }
        bfs(matrix, pacific, pacificQueue, m, n);
        bfs(matrix, atlantic, atlanticQueue, m, n);
        
        
        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] > 0 && atlantic[i][j] > 0) {
                    res.push_back({i, j});
                }                
            }
        }
        return res;
    }
    
    void bfs(vector<vector<int>>& matrix, vector<vector<int>>& water, queue<pair<int, int>>& posQueue, int m, int n) {
        while (!posQueue.empty()) {
            int row = posQueue.front().first, col = posQueue.front().second;    
            posQueue.pop();
            for (int i = 0; i < 4; i++) {
                int newRow = row + directions[i][0], newCol = col + directions[i][1];
                if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || matrix[newRow][newCol] < matrix[row][col] || water[newRow][newCol] != 0) {
                    continue;
                }
                water[newRow][newCol] = 1;                
                posQueue.push({newRow, newCol});
            }
        }
    }
};