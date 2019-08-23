class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if len(intervals) == 0:
            return 0
        intervals = sorted(intervals, key=lambda interval: interval[1])
        end = intervals[0][1]
        count = 1
        for interval in intervals[1:]:
            if interval[0] >= end:
                end = interval[1]
                count += 1
        return len(intervals) - count
        