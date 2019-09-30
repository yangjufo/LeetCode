class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def subset(nums, current, ans):            
            ans.append(current.copy())
            for i in range(len(nums)):
                current.append(nums[i])
                subset(nums[i + 1:], current, ans)
                del current[-1]
        ans = list()
        subset(nums, [], ans)
        return ans
            
            
            