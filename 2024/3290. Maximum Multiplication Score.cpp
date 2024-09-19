class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<vector<long long>> dp(b.size(), vector<long long>(4, LONG_MIN));
        dp[0][0] = dp[1][1] = dp[2][2] = dp[3][3] = 0;
        for (int i = 0; i < b.size(); i++) {
            dp[i][0] = (long long)a[0] * b[i];
            if (i > 0) {
                dp[i][0] = max((long long)a[0] * b[i], dp[i - 1][0]);
                dp[i][1] = max(dp[i - 1][1], (long long)a[1] * b[i] + dp[i - 1][0]);
            }
            if (i > 1) {
                dp[i][2] = max(dp[i - 1][2], (long long)a[2] * b[i] + dp[i - 1][1]);
            }
            if (i > 2) {
                dp[i][3] = max(dp[i - 1][3], (long long)a[3] * b[i] + dp[i - 1][2]);
            }
        }
        return dp.back()[3];
    }
};