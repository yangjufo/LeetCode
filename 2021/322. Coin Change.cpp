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