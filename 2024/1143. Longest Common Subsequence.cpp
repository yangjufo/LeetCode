class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));
        dp[0][0] = 0;
        for (int i = 0; i < text1.length(); i++) {
            for (int j = 0; j < text2.length(); j++) {
                dp[i + 1][j + 1] = text1[i] == text2[j] ? dp[i][j] + 1 : max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        return dp[text1.length()][text2.length()];
    }
};