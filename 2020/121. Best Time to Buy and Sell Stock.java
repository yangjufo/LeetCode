class Solution {
    public int maxProfit(int[] prices) {
        int buy = Integer.MAX_VALUE, profit = 0;
        for (int p : prices) {
            if (p - buy > profit)
                profit = p - buy;
            if (p < buy)
                buy = p;
        }
        return profit;
    }
}
