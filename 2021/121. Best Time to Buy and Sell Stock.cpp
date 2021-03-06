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

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, lowestBuy = INT_MAX;
        for (int p : prices) {
            maxProfit = max(maxProfit, p - lowestBuy);
            lowestBuy = min(lowestBuy, p);
        }
        return maxProfit;
    }
};