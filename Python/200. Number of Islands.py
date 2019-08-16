class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if len(grid) == 0 or len(grid[0]) == 0:
            return 0
        m, n = len(grid), len(grid[0])        
        ans = 0
        def dfs(i, j):
            grid[i][j] = '0'
            dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
            for d in dirs:
                x, y = i + d[0], j + d[1]
                if x < 0 or x >= m or y < 0 or y >=n or grid[x][y] == '0':
                    continue
                dfs(x, y)            
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':                    
                    ans += 1
                    dfs(i, j)
        return ans
                    