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

class Solution {
public:
    int climbStairs(int n) {
        int prev1 = 1, prev2 = 0;
        for (int i = 1; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 0, prev1 = 1;
        for (int i = 1; i <= n; i++) {
            int curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }