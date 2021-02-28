class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int c : coins) {
            for (int a = c; a <= amount; a++) {
                if (a >= c) {
                    dp[a] += dp[a - c];
                }
            }
        }
        return dp[amount];
    }
};