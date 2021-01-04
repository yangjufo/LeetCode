class Solution {
public:
    int numDistinct(string s, string t) {
        long dp[s.length() + 1][t.length() + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < s.length() + 1; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i < s.length() + 1; i++) {
            for (int j = 1; j < t.length() + 1; j++) {
                dp[i][j] = dp[i - 1][j];
                if (s[i - 1] == t[j - 1] && dp[i - 1][j - 1] > 0) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }            
        }        
        return dp[s.length()][t.length()];
    }
};