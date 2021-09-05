class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = (m == 0) ? 0 : grid[0].size();
        if (m == 0 || n == 0) return 0;
        
        int dp[m][n];                        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {                
                if (i == 0) {
                    dp[i][j] = (j == 0) ? grid[i][j] : dp[i][j - 1] + grid[i][j]; 
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }
        }
        
        return dp[m - 1][n - 1];
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size()));
        for (int i = 0; i < grid.size(); i++) {
            dp[i][0] = grid[i][0] + (i > 0 ? dp[i - 1][0] : 0);
        }
        for (int j = 0; j < grid[0].size(); j++) {
            dp[0][j] = grid[0][j] + (j > 0 ? dp[0][j - 1] : 0);
        }
        for (int i = 1; i < grid.size(); i++) {            
            for (int j = 1; j < grid[0].size(); j++) {                                       
                dp[i][j] = grid[i][j] + min(dp[i -1][j], dp[i][j - 1]);
            }
        }
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};