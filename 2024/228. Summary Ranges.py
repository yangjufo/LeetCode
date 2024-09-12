class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if len(nums) == 0:
            return []
        start = end = nums[0]
        ans = list()
        for i in range(1, len(nums)):
            if nums[i] - nums[i - 1] == 1:
                end = nums[i]
            else:
                if start == end:
                    ans.append(str(start))
                else:
                    ans.append(str(start)+"->"+str(end))
                start = end = nums[i]
        if start == end:
            ans.append(str(start))
        else:
            ans.append(str(start)+"->"+str(end))
        return ans


class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if len(nums) == 0:
            return []
        ans = list()
        i = 0
        while i < len(nums):
            start = nums[i]
            while i + 1 < len(nums) and nums[i] + 1 == nums[i + 1]:
                i += 1
            if start != nums[i]:
                ans.append(str(start) + "->" + str(nums[i]))
            else:
                ans.append(str(start))
            i += 1
        return ans
