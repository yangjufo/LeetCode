class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();        
        if (n <= 1) return 0;
        
        int dp[n][2];
        for (int i = 0; i < n; i++) {
            dp[i][0] = -1e9;
            dp[i][1] = -1e9;
        }
        
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        
        
        dp[1][0] = max(0, prices[1] - prices[0]);
        dp[1][1] = max(-prices[0], -prices[1]);
                
        for (int i = 2; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], prices[i] + dp[i - 1][1]);
            dp[i][1] = max(dp[i - 1][1], -prices[i] + dp[i - 2][0]);
        }
        
        return dp[n - 1][0];        
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold = INT_MIN, held = INT_MIN, reset = 0;
        
        for (int price : prices) {
            int preSold = sold;
            
            sold = held + price;
            held = max(held, reset - price);
            reset = max(reset, preSold);
        }
        
        return max(sold, reset);
    }
};