class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        def sortFunc(interval: List[int]):
            return (interval[1], interval[0])
        points.sort(key=sortFunc)
        count = 0
        i = 0
        while i < len(points):
            currEnd = points[i][1]
            count += 1
            while i < len(points) and currEnd >= points[i][0]:
                i += 1
        return count
