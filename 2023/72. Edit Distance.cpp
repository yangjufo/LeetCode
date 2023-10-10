class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        if (m == 0 || n == 0) {
            return m + n;
        }
        int dp[m + 1][n + 1];
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int left = dp[i - 1][j] + 1;
                int down = dp[i][j - 1] + 1;
                int left_down = dp[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1]) {
                    left_down += 1;
                }
                dp[i][j] = min(left, min(down, left_down));
                cout << dp[i][j] << " ";
            }
        }
        return dp[m][n];
    }
};