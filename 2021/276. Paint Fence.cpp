class Solution {
public:
    int numWays(int n, int k) {        
        vector<int> dp(max(n + 1, 3), 0);
        dp[0] = 0;
        dp[1] = k;
        dp[2] = k * k;
        
        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 2] + dp[i - 1]) * (k - 1);
        }
        
        return dp[n];
    }
};

class Solution {
public:
    int numWays(int n, int k) {
        vector<int> dp(max(n + 1, 3), 0);
        dp[0] = 0;
        dp[1] = k;
        dp[2] = k * k;
        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 2] + dp[i - 1]) * (k - 1);
        }
        return dp[n];
    }
};