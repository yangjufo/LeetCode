class Solution {
public:
    int numTrees(int n) {
        int dp[n + 1];
        std::fill(dp, dp + n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }        
        return dp[n];
    }
};

class Solution {
public:
    int numTrees(int n) {
        int dp[n + 1];
        fill(dp, dp + n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};

class Solution {
public:
    vector<int> mem;
    int numTrees(int n) {
        mem.resize(20, -1);
        return numTrees(1, n);
    }
    
    int numTrees(int left, int right) {        
        if (left > right) return 1;    
        if (mem[right - left + 1] > 0) return mem[right - left + 1];        
        int res = 0;
        for (int i = left; i <= right; i++) {
            int leftCount = numTrees(left, i - 1);
            int rightCount = numTrees(i + 1, right);
            res += leftCount * rightCount;
        }
        mem[right - left + 1] = res;
        return mem[right - left + 1];
    }
};