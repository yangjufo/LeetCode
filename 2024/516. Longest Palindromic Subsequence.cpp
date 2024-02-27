class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
        for (int i = s.length() - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < s.length(); j++) {
                dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] + 2 : max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
        return dp[0][s.length() - 1];
    }
};