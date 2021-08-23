class Solution {
public:
    int mod = 1e9 + 7;
    int findDerangement(int n) {
        if (n == 0) return 1;
        if (n == 1) return 0;
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            dp[i] = ((long)(i - 1) * (dp[i - 1] + dp[i - 2])) % mod;
        }
        return dp[n];
    }
};