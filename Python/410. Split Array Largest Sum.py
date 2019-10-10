class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        left = max(nums)
        right = sum(nums)
        while left < right:
            mid = left + (right - left) // 2
            tmp = 0
            count = 1
            for n in nums:
                if tmp + n > mid:
                    tmp = 0
                    count += 1
                tmp += n
            if count > m:
                left = mid + 1
            else:
                right = mid
        return left
