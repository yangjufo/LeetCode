class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if prices is None or len(prices) == 0:
            return 0
        buy = prices[0]
        profit = 0
        for p in prices:
            profit = max(p - buy, profit)
            if p < buy:
                buy = p
        return profit