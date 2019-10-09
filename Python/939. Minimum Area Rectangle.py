class Solution:
    def minAreaRect(self, points: List[List[int]]) -> int:
        seen = set()
        ans = float('inf')
        for x in points:
            for y in seen:
                if (x[0], y[1]) in seen and (y[0], x[1]) in seen:
                    ans = min(ans, abs(x[0] - y[0]) * abs(x[1] - y[1]))
            seen.add(tuple(x))
        return ans if ans < float('inf') else 0
