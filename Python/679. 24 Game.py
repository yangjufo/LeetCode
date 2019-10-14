class Solution:
    def judgePoint24(self, nums: List[int]) -> bool:
        def compute(a, b):            
            ans = [a + b, a * b, a - b, b - a]
            if a != 0:
                ans.append(b / a)
            if b != 0:
                ans.append(a / b)
            return ans
        def dfs(nums):            
            if len(nums) == 1:                
                if abs(nums[0] - 24) <= 0.001:
                    return True                
                return False
            else:
                for i in range(len(nums)):
                    for j in range(i + 1, len(nums)):
                        for c in compute(nums[i], nums[j]):
                            nextRound = [c]
                            for k in range(len(nums)):
                                if k != i and k != j:
                                    nextRound.append(nums[k])
                            if dfs(nextRound):
                                return True
        return dfs(nums)