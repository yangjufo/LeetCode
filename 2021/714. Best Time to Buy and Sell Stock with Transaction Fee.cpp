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

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int profit = 0, buy = INT_MAX;
        for (int price : prices) {
            if (price + fee < buy) {
                buy = price + fee;
            }
            if (price > buy) {
                profit += price - buy;
                buy = price;
            }
        }
        return profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = INT_MAX, profit = 0;
        for (int p : prices) {
            buy = min(p + fee, buy);
            if (p > buy) {
                profit += p - buy;
                buy = p;
            }
        }
        return profit;
    }
};