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

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX, profit = 0;
        for (int n : prices) {
            if (n < buy) {
                buy = n;
            } else {
                profit = max(n - buy, profit);
            }
        }
        return profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX, profit = 0;
        for (int p : prices) {
            buy = min(buy, p);
            profit = max(p - buy, profit);
        }
        return profit;
    }
};