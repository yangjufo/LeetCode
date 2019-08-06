class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        counts = [amount + 1] * (amount + 1)
        counts[0] = 0
        for i in range(1, amount + 1):
            for coin in coins:
                if coin <= i and counts[i - coin] != -1:
                    counts[i] = min(counts[i - coin] + 1, counts[i])
        return -1 if counts[amount] > amount else counts[amount]
