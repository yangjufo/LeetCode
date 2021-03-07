class Solution:
    def minElements(self, nums: List[int], limit: int, goal: int) -> int:
        for n in nums:
            goal -= n
        if goal < 0:
            goal = -goal
        return (goal + limit - 1) // limit