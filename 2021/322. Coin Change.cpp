class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {        
        int amountCoins[amount + 1];
        amountCoins[0] = 0;
        for (int i = 1; i <= amount; i++) amountCoins[i] = amount + 1;
        
        for (int i = 1; i <= amount; i++) {
            for (int c : coins) {
                if (c <= i && amountCoins[i - c] + 1 < amountCoins[i]) {
                    amountCoins[i] = amountCoins[i - c] + 1;
                }
            }
        }
        
        return amountCoins[amount] > amount ? -1 : amountCoins[amount];
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);        
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int c : coins) {
                if (c <= i) {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }                
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int c : coins) {
                if (c <= i) {
                    dp[i] = min(dp[i], 1 + dp[i - c]);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};