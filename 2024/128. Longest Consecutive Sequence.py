class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0

        def find(parents, x):
            if parents[x] != x:
                parents[x] = find(parents, parents[x])
            return parents[x]

        def union(parents, ranks, x, y):
            x_p = find(parents, x)
            y_p = find(parents, y)
            if x_p != y_p:
                parents[y_p] = x_p
                ranks[x_p] += ranks[y_p]
        parents = defaultdict(int)
        ranks = defaultdict(int)
        for n in nums:
            parents[n] = n
            ranks[n] = 1
        for n in nums:
            if n - 1 in parents:
                union(parents, ranks, n - 1, n)
            if n + 1 in parents:
                union(parents, ranks, n + 1, n)
        return max(ranks.values())


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        count = defaultdict(int)
        ans = 0
        for n in nums:
            left = count[n - 1]
            right = count[n + 1]
            total = left + right + 1
            ans = max(ans, total)
            count[n] = total
            count[n - left] = total
            count[n + right] = total
        return ans
