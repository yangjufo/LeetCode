class Solution {
public:
    int kInversePairs(int n, int k) {
        int dp[n + 1][k + 1];
        memset(dp, 0, sizeof(dp));
        
        int mod = 1000'000'007;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j == 0) {
                    dp[i][j] = 1;
                } else {
                    int val = (dp[i - 1][j] + mod - ((j - i) >= 0 ? dp[i - 1][j - i] : 0)) % mod;
                    dp[i][j] = (dp[i][j - 1] + val) % mod;
                }
            }
        }
        return  (dp[n][k] + mod - (k > 0 ? dp[n][k - 1] : 0)) % mod;
    }
};