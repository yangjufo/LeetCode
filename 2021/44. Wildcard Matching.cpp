class Solution {
public:
    bool isMatch(string s, string p) {
        int dp[s.length() + 1][p.length() + 1];
        memset(dp, 0, sizeof(dp));                
        dp[0][0] = 1;
        for (int i = 1; i <= s.length(); i++) {
            dp[i][0] = 0;
        }
        for (int j = 1; j <= p.length(); j++) {
            dp[0][j] = p[j - 1] == '*' && dp[0][j - 1] == 1;
        }
        
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 1; j <= p.length(); j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else {
                    dp[i][j] = (s[i- 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
                }         
            }
        }
        
        return dp[s.length()][p.length()];
    }
};