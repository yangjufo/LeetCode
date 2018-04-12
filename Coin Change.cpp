class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        int res[amount + 1];        
        fill_n(res, amount+1, amount + 1);
        res[0] = 0;
        for (int i = 1; i < amount + 1; i++){
            for(int j = 0; j < coins.size(); j++){
                if (coins[j] <= i){
                    res[i] = min(res[i], res[i - coins[j]] + 1);
                }
            }
        }
        return res[amount] > amount ? -1 : res[amount];
    }
};