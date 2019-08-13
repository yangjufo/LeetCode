class Solution:
    def rob(self, nums: List[int]) -> int:        
        prev = curr = 0
        for num in nums:
            tmp = curr
            curr = max(prev + num, curr)
            prev = tmp
        return curr