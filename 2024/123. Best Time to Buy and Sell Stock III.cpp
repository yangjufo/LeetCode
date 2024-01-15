class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> left(prices.size(), 0), right(prices.size(), 0);
        int leftMin = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            left[i] = max(left[i - 1], prices[i] - leftMin);
            leftMin = min(leftMin, prices[i]);
        }
        int rightMax = prices.back();
        for (int i = prices.size() - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], rightMax - prices[i]);
            rightMax = max(rightMax, prices[i]);
        }
        int ans = 0;
        for (int i = 0; i < prices.size(); i++) {
            ans = max(ans, left[i] + right[i]);
        }
        return ans;
    }
};