class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = INT_MAX, maxProfit = 0;
        for (int p : prices) {
            minBuy = min(p, minBuy);
            maxProfit = max(maxProfit, p - minBuy);
        }
        return maxProfit;

    }
};