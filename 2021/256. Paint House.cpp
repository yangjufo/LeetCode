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