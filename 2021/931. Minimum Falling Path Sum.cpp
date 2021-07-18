class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), minPath = INT_MAX;
        vector<vector<int>> dp(m, vector<int>(n, 0));        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {                
                dp[i][j] = matrix[i][j];
                if (i > 0) {
                    dp[i][j] += min((j > 0 ? dp[i - 1][j - 1] : 101), min((j + 1 < n ? dp[i - 1][j + 1] : 101), dp[i - 1][j]));
                }
                if (i + 1 == m) {
                    minPath = min(minPath, dp[i][j]);
                }
            }
        }
        return minPath;
    }
};