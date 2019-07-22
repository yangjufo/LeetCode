class Solution:
    def shortestAlternatingPaths(self, n: int, red_edges: List[List[int]], blue_edges: List[List[int]]) -> List[int]:
        ans = [[0, 0]] + [[n * 2, n * 2] for i in range(0, n - 1)]
        bfs = [[0, 0], [0, 1]]
        G = [[[], []] for i in range(0, n)]
        for i, j in red_edges:
            G[i][0].append(j)
        for i, j in blue_edges:
            G[i][1].append(j)
        for i, c in bfs:
            for j in G[i][c]:
                if ans[j][c] == n * 2:
                    ans[j][c] = ans[i][1 - c] + 1
                    bfs.append([j, 1 - c])
        return [x if x < n * 2 else -1 for x in map(min, ans)]
                    