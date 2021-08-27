class Solution {
public:
    int maxA(int n) {        
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            dp[i] = i;
            for (int j = 1; j + 3 <= i; j++) {
                dp[i] = max(dp[i], dp[j] * (i - j - 1));
            }
        }
        return dp[n];
    }
};

class Solution {
public:
    int maxA(int n) {
        if (n <= 6) return n;
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= 6; i++)  {
            dp[i] = i;
        }
        for (int i = 7; i <= n; i++) {
            dp[i] = max(dp[i - 4] * 3, dp[i - 5] * 4);
        }
        return dp[n];
    }
};