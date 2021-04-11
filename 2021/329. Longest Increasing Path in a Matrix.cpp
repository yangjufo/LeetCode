class Solution {
public:    
    int dirs[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), maxLen = 0;
        vector<vector<int>> mem(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] >= 0) {
                    maxLen = max(dfs(matrix, mem, i, j, m, n), maxLen);
                }                
            }
        }
        return maxLen;
    }
    
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& mem, int row, int col, int m, int n) {
        if (mem[row][col] > 0) return mem[row][col];                
        for (int i = 0; i < 4; i++) {
            int newRow = row + dirs[i][0], newCol = col + dirs[i][1];
            if (newRow >= m || newRow < 0 || newCol >= n || newCol < 0 || matrix[newRow][newCol] <= matrix[row][col]) continue;
            mem[row][col] = max(mem[row][col], dfs(matrix, mem, newRow, newCol, m, n) + 1);
        }
        if (mem[row][col] == 0) {
            mem[row][col] = 1;
        }
        return mem[row][col];
    }
};