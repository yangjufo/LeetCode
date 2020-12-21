class Solution {
public:
    int climbStairs(int n) {
        int dp[2];
        dp[0] = dp[1] = 1;
        int updateIndex = 0;
        for (int i = 2; i <= n; i++) {
            int tmp = dp[0] + dp[1];
            dp[updateIndex] = tmp;
            updateIndex = 1 - updateIndex;
        }
        return dp[1 - updateIndex];
    }
};