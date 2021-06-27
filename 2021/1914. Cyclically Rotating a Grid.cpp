class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < min(m + 1, n + 1) / 2; i++) {
            for (int j = 0; j < k % (m * 2 + n * 2 - 4 - i * 8); j++) {
                rotate(grid, i, i, m, n);
            }
        }
        return grid;        
    }
    
    void rotate(vector<vector<int>>& grid, int row, int col, int m, int n) {  
        int tmp = grid[row][col];
        for (int j = col; j < n - col - 1; j++) {
            grid[row][j] = grid[row][j + 1];
        }        
        for (int i = row; i < m - row - 1; i++) {
            grid[i][n - col - 1] = grid[i + 1][n - col - 1];
        }
        for (int j = n - col - 1; j > col; j--) {    
            grid[m - row - 1][j] = grid[m - row - 1][j - 1];
        }
        for (int i = m - row - 1; i > row + 1; i--) {      
            grid[i][col] = grid[i - 1][col];
        }
        grid[row + 1][col] = tmp;
    }
};