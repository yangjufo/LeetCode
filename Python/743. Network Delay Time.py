from collections import defaultdict

class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        edges = defaultdict(dict)                                   
        for t in times:
            edges[t[0]][t[1]] = t[2]
        h = [[0, K]]                
        visited = set()
        seen = set()
        while len(h) > 0 and len(visited) < N:
            cost, end = heapq.heappop(h)
            if end in visited:
                continue
            visited.add(end)            
            for v, w in edges[end].items():
                if (end, v) not in seen:
                    seen.add((end, v))
                    heapq.heappush(h, [cost + w, v]) 
        return cost if len(visited) == N else -1
                    
            
                
