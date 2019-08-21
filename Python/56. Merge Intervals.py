class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        ans = list()
        if len(intervals) == 0:
            return ans
        intervals = sorted(intervals)
        ans.append(intervals[0])        
        for interval in intervals[1:]:
            if interval[0] <= ans[-1][1]:                
                ans[-1][1] = max(ans[-1][1], interval[1])
            else:
                ans.append(interval)
        return ans