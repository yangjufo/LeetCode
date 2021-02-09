class Solution {
public:
    unordered_set<string> islands;
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = (m == 0) ? 0 : grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    string curr;
                    dfs(grid, m, n, i, j, i, j, curr);
                    islands.insert(curr);
                }
            }
        }
        return islands.size();
    }
    
    void dfs(vector<vector<int>>& grid, int m, int n, int row, int col, int startRow, int startCol, string& curr) {        
        grid[row][col] = 0;
        curr += to_string(row - startRow) + to_string(col - startCol);
        for (int i = 0; i < 4; i++) {
            int newRow = row + directions[i][0], newCol = col + directions[i][1];
            if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || grid[newRow][newCol] != 1) {
                continue;
            }
            dfs(grid, m, n, newRow, newCol, startRow, startCol, curr);
        }
    }
};