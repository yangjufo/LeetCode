class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        def subset(nums, current, ans):
            ans.append(current.copy())
            for i in range(len(nums)):
                if i != 0 and nums[i] == nums[i - 1]:
                    continue
                current.append(nums[i])
                subset(nums[i+1:], current, ans)
                del current[-1]
        nums = sorted(nums)
        ans = list()
        subset(nums, [], ans)
        return ans
        
        