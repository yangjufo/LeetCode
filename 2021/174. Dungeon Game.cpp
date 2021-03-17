class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        int dp[m][n];
        memset(dp, sizeof(dp), 0);        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {                
                dp[i][j] = (i == m - 1)
                    ? ((j == n - 1) ? dungeon[i][j] : dp[i][j + 1] + dungeon[i][j])
                    : ((j == n - 1) ? dp[i + 1][j] + dungeon[i][j] : max(dp[i + 1][j], dp[i][j + 1]) + dungeon[i][j]);
                if (dp[i][j] > 0) {
                    dp[i][j] = 0;
                }
            }
        }
        return 1 - dp[0][0];
    }
};