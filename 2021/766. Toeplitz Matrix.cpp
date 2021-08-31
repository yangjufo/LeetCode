class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = (m == 0) ? 0 : matrix[0].size();
        for (int j = n - 1; j >= 0; j--) {
            int row = 0, col = j;
            while (row + 1 < m && col + 1 < n && matrix[row + 1][col + 1] == matrix[0][j]) {
                row += 1;
                col += 1;
            }
            if (row + 1 < m && col + 1 < n) {
                return false;
            }
        }
        
        for (int i = 1; i < m; i++) {
            int row = i, col = 0;
            while (row + 1 < m && col + 1 < n && matrix[row + 1][col + 1] == matrix[i][0]) {
                row += 1;
                col += 1;
            }
            if (row + 1 < m && col + 1 < n) {
                return false;
            }
        }
        
        return true;
    }
};