class Solution:
    def findMin(self, nums: List[int]) -> int:
        start = 0
        end = len(nums) - 1
        while start < end:
            middle = (start + end) // 2
            if nums[middle] > nums[-1]:
                start = middle + 1
            else:
                end = middle
        return nums[start]
