class Solution:
    def findMissingRanges(self, nums: List[int], lower: int, upper: int) -> List[str]:
        ans = list()
        if len(nums) == 0:
            if upper == lower:
                ans.append(str(lower))
            else:
                ans.append(str(lower)+"->"+str(upper))
        for i, n in enumerate(nums):
            if i == 0:
                if n - lower > 1:
                    ans.append(str(lower)+"->"+str(n-1))
                elif n - lower == 1:
                    ans.append(str(lower))
            else:
                if n - nums[i - 1] > 2:
                    ans.append(str(nums[i-1]+1)+"->"+str(n-1))
                elif n - nums[i-1] == 2:
                    ans.append(str(nums[i-1]+1))
            if i == len(nums) - 1:
                if upper - n > 1:
                    ans.append(str(n+1)+"->"+str(upper))
                elif upper - n == 1:
                    ans.append(str(upper))
        return ans
