class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r2 = matrix.size() - 1, c2 = (r2 == 0) ? 0 : matrix[0].size() - 1;
        int r1 = 0, c1 = 0;
        while (r1 < r2 && c1 < c2) {
            for (int i = 0; i < c2 - c1; i++) {
                int tmp = matrix[r1][c1 + i];
                matrix[r1][c1 + i] = matrix[r2 - i][c1];
                matrix[r2 - i][c1] = matrix[r2][c2 - i];
                matrix[r2][c2 - i] = matrix[r1 + i][c2];
                matrix[r1 + i][c2] = tmp;                
            }
            r1++;
            c1++;
            r2--;
            c2--;
        }
    }
};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int row = 0; row < n / 2; row++) {
            for (int j = row; j < n - row - 1; j++) {
                int tmp = matrix[row][j];
                matrix[row][j] = matrix[n - 1 - j][row];
                matrix[n - 1 - j][row] = matrix[n - 1 - row][n - 1 - j];
                matrix[n - 1 - row][n - 1 - j] = matrix[j][n - 1 - row];
                matrix[j][n - 1 - row] = tmp;
            }
        }
    }
};