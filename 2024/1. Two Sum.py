class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        indexes = defaultdict(int)
        for i, n in enumerate(nums):
            if target - n in indexes:
                return [indexes[target - n], i]
            indexes[n] = i
        return []
