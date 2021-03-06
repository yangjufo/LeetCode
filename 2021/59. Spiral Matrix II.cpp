class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 1));
        int num = 1;
        for (int i = 0; i < (n + 1) / 2; i++) {
            for (int j = i; j < n - i; j++) {
                matrix[i][j] = num;
                num++;
            }
            for (int j = i + 1; j < n - i; j++) {
                matrix[j][n - 1 - i] = num;
                num++;
            }
            for (int j = n - 2 - i; j >= i; j--) {
                matrix[n - 1 - i][j] = num;
                num++;
            }
            for (int j = n - 2 - i; j > i; j--) {
                matrix[j][i] = num;
                num++;
            }
        }
        return matrix;
    }
};