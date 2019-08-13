class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        if m == 0 or n == 0:
            return 0
        paths = [[0 for i in range(n)] for j in range(m)]
        paths[0][0] = 1
        for i in range(0, m):
            for j in range(0, n):
                paths[i][j] += 0 if i == 0 else paths[i - 1][j]
                paths[i][j] += 0 if j == 0 else paths[i][j - 1]
        return paths[m - 1][n - 1]
