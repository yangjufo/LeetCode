class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int row = 0; row < n / 2; row++) {
            for (int j = row; j < n - row - 1; j++) {
                int curr = matrix[row][j];
                matrix[row][j] = matrix[n - 1 - j][row];
                matrix[n - 1 - j][row] = matrix[n - 1 - row][n - 1 - j];
                matrix[n - 1 - row][n - 1 - j] = matrix[j][n - 1 - row];
                matrix[j][n - 1 - row] = curr;
            }
        }
    }
};