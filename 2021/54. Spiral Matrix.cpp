class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = (m == 0) ? 0 : matrix[0].size();
        int row = 0, col = 0;
        vector<int> ans;
        while (row < m && col < n) {
            for (int j = col; j < n; j++) {
                ans.push_back(matrix[row][j]);
            }                                
            for (int i = row + 1; i < m; i++) {
                ans.push_back(matrix[i][n - 1]);
            }
            for (int j = n - 2; j >= col && row != m - 1; j--) {
                ans.push_back(matrix[m - 1][j]);
            }                             
            for (int i = m - 2; i > row && col != n - 1; i--) {
                ans.push_back(matrix[i][col]);
            }
            row++;
            col++;
            m--;
            n--;
        }
        return ans;
    }
};