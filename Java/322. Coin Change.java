class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] combs = new int[amount + 1];
        Arrays.fill(combs, -1);
        combs[0] = 0;        
        for (int i = 1; i < amount + 1; i++) {
            for (int j = 0; j < coins.length; j++) {
                if (coins[j] <= i && combs[i - coins[j]] != -1) {
                    if (combs[i] != -1)
                        combs[i] = Math.min(combs[i - coins[j]] + 1, combs[i]);
                    else
                        combs[i] = combs[i - coins[j]] + 1;
                }
            }
        }        
        return combs[amount];
    }
}