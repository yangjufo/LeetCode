class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, buyPrice = INT_MAX;
        for (int price : prices) {
            if (price < buyPrice) {
                buyPrice = price;
            } else if (price - buyPrice > res) {
                res = price - buyPrice;
            }
        }
        return res;
    }
};