class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0 || n == 1) return n;
        int ans = 1;
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        bool by2 = true;
        for (int i = 2; i <= n; i++) {
            dp[i] = by2 ? dp[i / 2] : dp[(i - 1) / 2] + dp[(i + 1) / 2];
            ans = max(ans, dp[i]);
            by2 = !by2;
        }
        return ans;
    }
};