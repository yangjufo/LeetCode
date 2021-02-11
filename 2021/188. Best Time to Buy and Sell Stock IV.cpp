class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k <= 0 || prices.size() <= 1) return 0;
        
        int cost[k], profit[k];
        fill(cost, cost + k, INT_MAX);
        fill(profit, profit + k, 0);
        
        for (int p : prices) {
            cost[0] = min(p, cost[0]);
            profit[0] = max(profit[0], p - cost[0]);
            
            for (int i = 1; i < k; i++) {
                cost[i] = min(cost[i], p - profit[i - 1]);
                profit[i] = max(profit[i], p - cost[i]);
            }
        }
        
        return profit[k - 1];
    }
};

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1 || k == 0) return 0;
        
        int res = 0;
        if (2 * k >= n) {
            for (int i = 1; i < prices.size(); i++) {
                res += max(prices[i] - prices[i - 1], 0);
            }
            return res;
        }
        
        int dp[n][k + 1][2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j][0] = dp[i][j][1] = -1e9;
            }
        }
        
        dp[0][0][0] = 0;
        dp[0][1][1] = -prices[0];
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                if (j > 0) {
                    dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
                }
            }
        }
        
        for (int j = 0; j <= k; j++) {
            res = max(res, dp[n - 1][j][0]);
        }
        
        return res;
    }
};