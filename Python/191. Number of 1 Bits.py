class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans = 0
        while n != 0:
            ans += 1
            n &= (n - 1)
        return ans
        