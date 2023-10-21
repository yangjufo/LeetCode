class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> count(m, vector<int>(n));
        count[startRow][startColumn] = 1;
        int total = 0, mod = (1e9 + 7);
        for (int mv = 0; mv < maxMove; mv++) {
            vector<vector<int>> tmp(m, vector<int>(n));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == m - 1) {
                        total = (total + count[i][j]) % mod;
                    }
                    if (j == n - 1) {
                        total = (total + count[i][j]) % mod;
                    }
                    if (i == 0) {
                        total = (total + count[i][j]) % mod;
                    }
                    if (j == 0) {
                        total = (total + count[i][j]) % mod;
                    }
                    tmp[i][j] = (((i > 0 ? count[i - 1][j] : 0) + (i < m - 1 ? count[i + 1][j] : 0)) % mod + ((j > 0 ? count[i][j - 1] : 0) + (j < n - 1 ? count[i][j + 1] : 0)) % mod) % mod;
                }
            }
            count = tmp;
        }
        return total;
    }
};