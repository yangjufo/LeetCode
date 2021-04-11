class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size() - 1, lane = 2;
        vector<vector<int>> dp(n + 1, vector<int>(4, n));
        return dfs(obstacles, dp, 2, 0, n);
    }
    
    int dfs(vector<int>& obstacles, vector<vector<int>>& dp, int lane, int i, int n) {   
        if (dp[i][lane] < n) return dp[i][lane];
        if (i >= n) return 0;        
        if (obstacles[i + 1] == lane) {
            for (int j = 1; j <= 3; j++) {
                if (j == lane || obstacles[i] == j) continue;                
                dp[i][lane] = min(dp[i][lane], dfs(obstacles, dp, j, i + 1, n) + 1);
            }            
        } else {
            dp[i][lane] = dfs(obstacles, dp, lane, i + 1, n);
        }
        return dp[i][lane];
    }
};

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size() - 1;
        int dp[n][3];
        dp[0][1] = 0;
        dp[0][0] = dp[0][2] = 1;        
        for (int i = 1; i < n; i++) {
            for (int r = 0; r <= 2; r++) {
                if (obstacles[i + 1] == r + 1 || obstacles[i] == r + 1) {
                    dp[i][r] = n;
                } else {
                    dp[i][r] = min(dp[i - 1][r], min(dp[i - 1][(r + 1) % 3], dp[i - 1][(r + 2) % 3]) + 1);
                }                
            }               
        }
        return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
    }
};