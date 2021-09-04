class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) return 0;
        int dp[m][n];
        for (int i = 0; i <m; i++) dp[i][0] = 1;
        for (int j = 0; j <n; j++) dp[0][j] = 1;
        
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));        
        for (int i = 0; i < m; i++) {            
            for (int j = 0; j < n; j++) {        
                if (i == 0 && j == 0) {
                    dp[i + 1][j + 1] = 1;
                } else {
                    dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j];
                }                
            }
        }
        return dp[m][n];
    }
};