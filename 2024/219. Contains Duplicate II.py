class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        indexes = defaultdict(int)
        for i, n in enumerate(nums):
            if n in indexes and i - indexes[n] <= k:
                return True
            indexes[n] = i
        return False
