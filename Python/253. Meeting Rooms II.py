class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        intervals = sorted(intervals)
        print(intervals)
        endQueue = list()
        for interval in intervals:
            if len(endQueue) != 0 and interval[0] >= endQueue[0]:
                heapq.heappop(endQueue)
            heapq.heappush(endQueue, interval[1])
        return len(endQueue)
