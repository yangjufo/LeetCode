class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = nums[0] ^ 0
        for i in range(1, len(nums)):
            ans ^= i ^ nums[i]
        return ans ^ len(nums)
