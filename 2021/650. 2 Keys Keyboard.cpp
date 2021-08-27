class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, n + 1);
        dp[1] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = min(dp[i], i);
            for (int j = 2; j * i <= n; j++) {
                dp[j * i] = min(dp[j * i], dp[i] + j);
            }
        }
        return dp[n];
    }
};