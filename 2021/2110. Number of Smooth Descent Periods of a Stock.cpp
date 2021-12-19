class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        vector<long long> dp(prices.size(), 1);
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] == prices[i - 1] - 1) {
                dp[i] += dp[i - 1];
            }
        }
        long long res = 0;
        for (long long d : dp) {
            res += d;
        }
        return res;
    }
};