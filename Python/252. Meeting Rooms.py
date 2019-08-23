class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        intervals = sorted(intervals)
        def overlap(left, right):
            return left[1] > right[0] and left[0] < right[1]
        for i in range(len(intervals) - 1):
            if overlap(intervals[i], intervals[i + 1]):
                return False
        return True