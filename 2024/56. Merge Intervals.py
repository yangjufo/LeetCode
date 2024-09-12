class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        def sortFunc(interval: List[int]):
            return interval[0]
        intervals.sort(key=sortFunc)
        i = 0
        ans = list()
        while i < len(intervals):
            curr = intervals[i]
            while i < len(intervals) and intervals[i][0] <= curr[1]:
                curr[1] = max(intervals[i][1], curr[1])
                i += 1
            ans.append(curr)
        return ans
