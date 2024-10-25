class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = m - 1; i >= 0; i--) {
            int val = matrix[i][0];
            for (int row = i, col = 0; row < m && col < n; row += 1, col += 1) {
                if (matrix[row][col] != val) {
                    return false;
                }
            }
        }
        for (int j = 1; j < n; j++) {
            int val = matrix[0][j];
            for (int row = 0, col = j; row < m && col < n; row += 1, col += 1) {
                if (matrix[row][col] != val) {
                    return false;
                }
            }
        }
        return true;
    }
};