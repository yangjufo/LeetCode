class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buyPrice = INT_MAX, res = 0;
        
        for (int p : prices) {
            if (p < buyPrice) {
                buyPrice = p;
            }
            if (p - fee > buyPrice) {
                res += p - fee - buyPrice;
                buyPrice = p - fee;
            }
        }
        return res;
    }
};