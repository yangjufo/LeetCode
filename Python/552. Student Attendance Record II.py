class Solution:
    def checkRecord(self, n: int) -> int:
        mod = 10**9 + 7
        dp = [0] * (6 if n <= 5 else n + 1)
        dp[0] = 1
        dp[1] = 2
        dp[2] = 4
        dp[3] = 7
        for i in range(4, n + 1):
            dp[i] = ((2 * dp[i - 1]) % mod + (mod - dp[i-4])) % mod
        ans = dp[n]        
        for i in range(1, n + 1):
            ans += (dp[i - 1] * dp[n - i]) % mod
        return (int)(ans % mod)
            
            
        
        
        