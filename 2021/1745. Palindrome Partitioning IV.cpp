class Solution {
public:
    bool checkPartitioning(string s) {
        if (s.length() == 3) return true;
        int len = s.length();        
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i; j < len; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : true;
                }                
                else dp[i][j] = false;
            }
        }        
        
        for (int i = 1; i < len - 1; i++) {
            for (int j = i; j < len - 1; j++) {
                if (dp[0][i - 1] && dp[i][j] && dp[j + 1][len - 1]) return true;
            }
        }
        return false;
    }        
};