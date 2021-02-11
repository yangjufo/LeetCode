class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice = INT_MAX, profit = 0;
        for (int p : prices) {
            if (p < buyPrice) {
                buyPrice = p;
            }
            if (p > buyPrice) {
                profit += p - buyPrice;
                buyPrice = p;
            }
        }
        return profit;
    }