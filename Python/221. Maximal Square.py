class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        rows = len(matrix)
        cols = 0 if rows == 0 else len(matrix[0])
        dp = [[0 for j in range(cols + 1)] for i in range(rows + 1)]
        maxlen = 0        
        for i in range(1, rows + 1):
            for j in range(1, cols + 1):
                if matrix[i - 1][j - 1] == '1':                    
                    dp[i][j] = min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1
                    maxlen = max(maxlen, dp[i][j])
        return maxlen * maxlen
