class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        edges = dict()
        nodes = set(nums)
        ans = 0        
        for num in nodes:
            if num - 1 not in nodes:
                curr = num
                curr_len = 1
                while curr + 1 in nodes:
                    curr += 1
                    curr_len += 1
                ans = max(ans, curr_len)
        return ans
            