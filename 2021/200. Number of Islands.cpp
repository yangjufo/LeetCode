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