class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;        
        int minPrice = prices[0];
        int maxPrice = 0;
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++){
            if (prices[i] < minPrice){
                minPrice = prices[i];
                maxPrice = prices[i];
            }
            if (prices[i] > maxPrice){
                maxPrice = prices[i];
            }  
            if (maxPrice - minPrice > maxProfit){
                maxProfit = maxPrice - minPrice;
            }
        }
        return maxProfit;
    }
};