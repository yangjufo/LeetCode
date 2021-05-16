class Solution {
public:    
    int mod = 1'000'000'007;    
    int rearrangeSticks(int n, int k) {        
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = (int)(((long)(i - 1)*dp[i - 1][j] + dp[i - 1][j - 1])%mod);
            }
        }
        return dp[n][k];
    }    
};