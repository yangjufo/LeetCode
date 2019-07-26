class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if nums is None or len(nums) == 0:
            return None
        ans = nums[0]
        tmp = 0
        for num in nums:
            tmp += num
            ans = max(tmp, ans)
            if tmp < 0:
                tmp = 0
        return ans
