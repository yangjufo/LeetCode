class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(1002, vector<int>(1002));
        dp[0][0] = 1;
        for (int i = 1; i <= k; i++) {
            dp[i][i] = 1;
            for (int j = 0; j <= k; j++) {
                dp[i][j] = (dp[i - 1][abs(j - 1)] + dp[i - 1][j + 1]) % (int)(1e9 + 7);
            }
        }
        return dp[k][abs(startPos - endPos)];
    }
};