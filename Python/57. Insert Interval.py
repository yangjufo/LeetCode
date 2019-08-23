class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        ans = list()
        added = False
        for interval in intervals:            
            if not added and interval[1] >= newInterval[0]:
                added = True
                if interval[0] <= newInterval[1]:
                    ans.append([min(interval[0], newInterval[0]), max(interval[1], newInterval[1])])
                if interval[0] > newInterval[1]:
                    ans.append(newInterval)
                    ans.append(interval)
            else:
                if len(ans) == 0 or interval[0] > ans[-1][1]:
                    ans.append(interval)
                else:
                    ans[-1][1] = max(interval[1], ans[-1][1])
        if not added:
            ans.append(newInterval)
        return ans
                    
                    
            