class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        
        int leftProfit[n], rightProfit[n + 1];
        fill(leftProfit, leftProfit + n, 0);
        fill(rightProfit, rightProfit + n + 1, 0);
        
        int leftBuyMin = prices[0], rightSellMax = prices[n - 1];
        
        for (int l = 1; l < n; l++) {
            leftProfit[l] = max(leftProfit[l - 1], prices[l] - leftBuyMin);
            leftBuyMin = min(leftBuyMin, prices[l]);                        
        }
        
        for (int r = n - 1; r >= 0; r--) {
            rightProfit[r] = max(rightProfit[r + 1], rightSellMax - prices[r]);
            rightSellMax = max(rightSellMax, prices[r]);
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, leftProfit[i] + rightProfit[i]);
        }
        return res;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int t1Cost = INT_MAX, t2Cost = INT_MAX, t1Profit = 0, t2Profit = 0;
        
        for (int p : prices) {
            t1Cost = min(p, t1Cost);
            t1Profit = max(t1Profit, p - t1Cost);
            
            t2Cost = min(t2Cost, p - t1Profit);
            t2Profit = max(t2Profit, p - t2Cost);
        }
        
        return t2Profit;
    }
};