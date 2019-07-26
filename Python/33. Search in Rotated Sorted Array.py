class Solution:
    def search(self, nums: List[int], target: int) -> int:
        start = 0
        end = len(nums) - 1
        while start < end:
            middle = (start + end) // 2
            if nums[middle] > nums[-1]:
                start = middle + 1
            else:
                end = middle
        realStart = start
        start = 0
        end = len(nums) - 1
        while start <= end:
            middle = (start + end) // 2
            realMiddle = (middle + realStart) % len(nums)
            if nums[realMiddle] == target:
                return realMiddle
            elif nums[realMiddle] < target:
                start = middle + 1
            else:
                end = middle - 1
        return -1
