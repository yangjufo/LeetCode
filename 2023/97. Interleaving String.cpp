class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return false;
        vector<bool> dp(s2.length() + 1, false);
        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                if (i == 0 && j == 0) {
                    dp[j] = true;
                }
                if (i == 0 && j != 0) {
                    dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
                }
                if (i != 0 && j == 0) {
                    dp[j] = dp[j] && s1[i - 1] == s3[i - 1];
                }
                if (i != 0 && j != 0) {
                    dp[j] = (dp[j - 1] && s2[j - 1] == s3[i + j - 1]) || (dp[j] && s1[i - 1] == s3[i + j - 1]);
                }
            }
        }
        return dp[s2.length()];
    }
};