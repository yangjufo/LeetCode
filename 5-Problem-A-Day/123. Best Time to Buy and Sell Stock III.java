class Solution {
    public int maxProfit(int[] prices) {
        int oneBuy = Integer.MAX_VALUE, twoBuy = Integer.MAX_VALUE;
        int oneProfit = 0, twoProfit = 0;
        for (int p : prices) {
            oneBuy = Math.min(oneBuy, p);
            oneProfit = Math.max(oneProfit, p - oneBuy);
            twoBuy = Math.min(twoBuy, p - oneProfit);
            twoProfit = Math.max(twoProfit, p - twoBuy);
        }
        return twoProfit;
    }
}
