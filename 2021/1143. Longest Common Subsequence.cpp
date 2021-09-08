class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        if (m == 0 || n == 0) return 0;
        int dp[m + 1][n + 1];       
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {                
               dp[i][j] = 0;
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {                
                if (text1[i] == text2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;                    
                } else {
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        
        return dp[m][n];
    }
};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));
        for (int i = 0; i < text1.length(); i++) {
            for (int j = 0; j < text2.length(); j++) {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                if (text1[i] == text2[j]) {
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
                }                
            }
        }
        return dp[text1.length()][text2.length()];
    }
};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1));
        for (int i = 0; i < text1.length(); i++) {
            for (int j = 0; j < text2.length(); j++) {
                if (text1[i] == text2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[text1.length()][text2.length()];
    }
};