class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int c : coins) {
                if (c > i || dp[i - c] == -1) {
                    continue;
                }
                if (dp[i] == -1 || dp[i] > dp[i - c] + 1){
                    dp[i] = dp[i - c] + 1;
                }
            }
        }
        return dp[amount];
    }
};