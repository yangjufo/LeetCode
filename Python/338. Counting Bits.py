class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        ans = [0] * (num + 1)
        i = 0
        b = 1
        while b <= num:
            while i < b and i + b <= num:
                ans[i + b] = ans[i] + 1
                i += 1
            i = 0
            b <<= 1
        return ans