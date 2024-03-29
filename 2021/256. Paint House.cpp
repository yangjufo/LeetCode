class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int N = costs.size();
        vector<vector<int>> dp(N + 1, vector<int>(3, 0));
        for (int i = 0; i < costs.size(); i++) {
            dp[i + 1][0] = min(dp[i][1], dp[i][2]) + costs[i][0];
            dp[i + 1][1] = min(dp[i][0], dp[i][2]) + costs[i][1];
            dp[i + 1][2] = min(dp[i][0], dp[i][1]) + costs[i][2];
        }
        return min(dp[N][0], min(dp[N][1], dp[N][2]));
    }
};

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0] = costs[0];        
        for (int i = 1; i < n; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
        }
        return min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
    }
};

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int prev[3] = {0}, curr[3] = {0};
        for (int i = 0; i < costs.size(); i++) {
            curr[0] = min(prev[1], prev[2]) + costs[i][0];
            curr[1] = min(prev[0], prev[2]) + costs[i][1];
            curr[2] = min(prev[0], prev[1]) + costs[i][2];
            for (int j = 0; j < 3; j++) {
                prev[j] = curr[j];
            }
        }
        return min(prev[0], min(prev[1], prev[2]));
    }
};