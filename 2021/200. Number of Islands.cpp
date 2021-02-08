class Solution {
public: 
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = (m == 0) ? 0 : grid[0].size();
        if (m == 0 || n == 0) return 0;        
        int count = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    dfs(grid, m, n, i, j, visited);
                    count++;
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<char>>& grid, int m, int n, int x, int y, vector<vector<bool>>& visited) {
        visited[x][y] = true;
        for (int* dir : directions) {
            int a = x + dir[0], b = y + dir[1];
            if (a < 0 || a >= m || b < 0 || b >= n || visited[a][b] || grid[a][b] == '0') {
                continue;
            }
            dfs(grid, m, n, a, b, visited);
        }
    }
};

class Solution {
public: 
    
    int count;
    vector<int> parents, ranks;
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = (m == 0) ? 0 : grid[0].size();
        parents.resize(m * n, -1);
        ranks.resize(m * n, 0);
        count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    parents[i * n + j] = i * n + j;
                    count++;
                }                                
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    if (i - 1 >= 0 && grid[i - 1][j] == '1') {
                        merge(i * n + j, (i -1) * n + j);
                    }
                    if (i + 1 < m && grid[i + 1][j] == '1') {
                        merge(i * n + j, (i + 1) * n + j);
                    }
                    if (j - 1 >= 0 && grid[i][j - 1] == '1') {
                        merge(i * n + j, i * n + j - 1);
                    }
                    if (j + 1 < n && grid[i][j + 1] == '1') {
                        merge(i * n + j, i * n + j + 1);
                    }
                }
            }
        }
        return count;    
    }
    
    int find (int node) {
        return (parents[node] == node) ? node : find(parents[node]);
    }
    
    void merge (int left, int right) {
        int pLeft = find(left), pRight = find(right);
        if (pLeft != pRight) {
            if (ranks[pLeft] < ranks[pRight]) {                
                parents[pLeft] = pRight;
            } else {
                if (ranks[pLeft] == ranks[pRight]) {
                    ranks[pLeft]++;
                }                
                parents[pRight] = pLeft;
            }
            count--;
        }
    }
};