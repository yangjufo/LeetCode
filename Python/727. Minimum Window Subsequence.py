class Solution:
    def minWindow(self, S: str, T: str) -> str:
        m, n = len(T), len(S)
        dp = [[0 for i in range(n + 1)] for j in range(m + 1)]
        for j in range(n + 1):
            dp[0][j] = j + 1
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if T[i - 1] == S[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = dp[i][j - 1]            
        start = 0
        max_len = n + 1        
        for j in range(1, n + 1):
            if dp[m][j] != 0:
                if j - dp[m][j] + 1 < max_len:
                    start = dp[m][j]
                    max_len = j - dp[m][j] + 1
        return "" if max_len == n + 1 else S[start - 1:start + max_len - 1]