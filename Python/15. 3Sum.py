class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        ans = list()
        for i in range(0, len(nums) - 2):
            if i == 0 or (i > 0 and nums[i] != nums[i - 1]):
                lo = i + 1
                hi = len(nums) - 1
                while lo < hi:
                    if nums[lo] + nums[hi] == -nums[i]:
                        ans.append([nums[i], nums[lo], nums[hi]])
                        while lo < hi and nums[lo] == nums[lo + 1]:
                            lo += 1
                        while lo < hi and nums[hi] == nums[hi - 1]:
                            hi -= 1
                        lo += 1
                        hi -= 1
                    elif nums[lo] + nums[hi] > -nums[i]:
                        hi -= 1
                    else:
                        lo += 1
        return ans
