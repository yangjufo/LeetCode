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
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 0; i + 1 < prices.size(); i++) {
            if (prices[i + 1] > prices[i]) {
                profit += prices[i + 1] - prices[i];
            }
        }
        return profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            profit += max(0, prices[i] - prices[i - 1]);
        }
        return profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, buy = INT_MAX;
        for (int p : prices) {            
            if (p > buy)
            {
                profit += p - buy;                
            }            
            buy = p;            
        }
        return profit;
    }
};