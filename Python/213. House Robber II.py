class Solution:
    def rob(self, nums: List[int]) -> int:
        prev = curr = 0
        for num in nums[1:]:
            tmp = curr
            curr = max(curr, prev + num)
            prev = tmp
        ans = curr
        prev = curr = 0
        for num in nums[:-1]:
            tmp = curr
            curr = max(curr, prev + num)
            prev = tmp
        return nums[0] if len(nums) == 1 else max(curr, ans)
