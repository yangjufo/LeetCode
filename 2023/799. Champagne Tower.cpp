class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row + 1, vector<double>(query_row + 1, 0.0));
        if (poured <= 1) {
            return query_row > 0 ? 0 : poured;
        }
        dp[0][0] = (poured - 1) * 1.0;
        for (int i = 1; i < query_row + 1; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j] / 2;
                } else if (j == i) {
                    dp[i][j] = dp[i - 1][j - 1] / 2;
                } else {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) / 2;
                }
                if (i < query_row) {
                    dp[i][j] -= 1;
                    dp[i][j] = max(0.0, dp[i][j]);
                }
            }
        }
        return dp[query_row][query_glass] > 1 ? 1 : dp[query_row][query_glass];
    }
};