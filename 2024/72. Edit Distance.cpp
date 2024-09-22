class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(
            word1.length() + 1,
            vector<int>(word2.length() + 1, word1.length() + word2.length()));
        for (int i = 0; i <= word1.length(); i++) {
            for (int j = 0; j <= word2.length(); j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 0;
                } else if (i == 0) {
                    dp[i][j] = dp[i][j - 1] + 1;
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + 1;
                } else {
                    if (word1[i - 1] == word2[j - 1]) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                    } else {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                    }
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                }
            }
        }
        return dp[word1.length()][word2.length()];
    }
};