class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if nums is None or len(nums) == 0:
            return None
        ans = nums[0]
        imax = ans
        imin = ans
        for num in nums[1:]:
            if num < 0:
                tmp = imax
                imax = imin
                imin = tmp

            imax = max(num, num * imax)
            imin = min(num, num * imin)

            ans = max(imax, ans)
        return ans
