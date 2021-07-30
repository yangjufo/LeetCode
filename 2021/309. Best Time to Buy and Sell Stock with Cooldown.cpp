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

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), profit = 0;
        vector<int> buy(n, 0), sell(n, 0);
        for (int i = 0; i < prices.size(); i++) {
            if (i == 0) {
                buy[i] = -prices[i];
            } else if (i == 1) {
                buy[i] = max(buy[i - 1], -prices[i]);
                sell[i] = max(0, prices[i] + buy[i - 1]);
            } else {
                buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);
                sell[i] = max(sell[i - 1], prices[i] + buy[i - 1]);
            }                        
            profit = max(profit, sell[i]);
        }        
        return profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // s1 => buy => s2
        // s2 => sell => s3
        // s1 => reset => s1
        // s2 => reset = s2
        // s3 => reset => s1
        vector<int> s1(n + 1, 0), s2(n + 1, 0), s3(n + 1, 0);
        s1[0] = 0, s2[0] = -prices[0], s3[0] = INT_MIN;
        for (int i = 1; i < prices.size(); i++) {
            s1[i] = max(s1[i - 1], s3[i - 1]);
            s2[i] = max(s2[i - 1], s1[i - 1] - prices[i]);
            s3[i] = s2[i - 1] + prices[i];
        }
        return max(s1[n - 1], s3[n - 1]);
    }
};