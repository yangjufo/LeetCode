class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        graph = defaultdict(list)
        for i, x in enumerate(stones):
            for j in range(i):
                y = stones[j]
                if x[0] == y[0] or x[1] == y[1]:
                    graph[i].append(j)
                    graph[j].append(i)
        
        N = len(stones)
        ans = 0
        
        seen = [False] * N
        for i in range(N):
            if not seen[i]:
                stack = [i]
                seen[i] = True
                while stack:
                    ans += 1
                    node = stack.pop()
                    for nei in graph[node]:
                        if not seen[nei]:
                            stack.append(nei)
                            seen[nei] = True
                ans -= 1
        return ans
        
class DSU:
    def __init__(self, N):
        self.p = [x for x in range(N)]
    
    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, x, y):
        xr = self.find(x)
        yr = self.find(y)
        self.p[xr] = yr

class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        N = len(stones)
        dsu = DSU(20000)
        for x, y in stones:
            dsu.union(x, y + 10000)
        return N - len({dsu.find(x) for x, y in stones})
                            
