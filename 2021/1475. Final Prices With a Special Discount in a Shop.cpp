class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {                
        vector<bool> done(prices.size(), false);
        for (int i = 0; i < prices.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (done[j] || prices[i] > prices[j]) continue;
                prices[j] -= prices[i];
                done[j] = true;                
            }
        }        
        return prices;
    }
};

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> indexes;
        for (int i = 0; i < prices.size(); i++) {
            while (!indexes.empty() && prices[indexes.top()] >= prices[i]) {
                prices[indexes.top()] -= prices[i];
                indexes.pop();
            }
            indexes.push(i);
        }    
        return prices;
    }
};