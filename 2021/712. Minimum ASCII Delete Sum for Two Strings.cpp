class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));\
        for (int i = 0; i < s1.length(); i++) {
            dp[i + 1][0] = dp[i][0] + s1[i];
        }
        for (int j = 0; j < s2.length(); j++) {
            dp[0][j + 1] = dp[0][j] + s2[j];
        }
        for (int i = 0; i < s1.length(); i++) {            
            for (int j = 0; j < s2.length(); j++) {                
                if (s1[i] == s2[j]) {
                    dp[i + 1][j + 1] = dp[i][j];
                } else {
                    dp[i + 1][j + 1] = min(dp[i + 1][j] + s2[j], dp[i][j + 1] + s1[i]);
                }                
            }
        }
        return dp[s1.length()][s2.length()];
    }
};