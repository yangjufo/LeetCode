class Solution:
    def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> int:
        def dis(a, b):
            return abs(a[0] - b[0]) + abs(a[1] - b[1])
        h = [[0, 0, 0]]
        seen = set()        
        while True:
            print(h)
            cost, w, taken = heapq.heappop(h)
            if (w, taken) in seen:
                continue            
            if w == len(workers):
                return cost            
            seen.add((w, taken))            
            for i in range(len(bikes)):
                if taken & (1 << i) == 0:
                    heapq.heappush(h, [cost + dis(workers[w], bikes[i]), w + 1, taken | (1 << i)])
            
            