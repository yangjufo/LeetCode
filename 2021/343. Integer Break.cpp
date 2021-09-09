class Solution {
public:
    vector<int> mem;
    int integerBreak(int n) {
        mem.resize(n + 1, -1);
        return backtrack(n);
    }
    
    int backtrack(int n) {
        if (n == 1) {
            mem[1] = 1;
        }
        if (mem[n] > 0) {
            return mem[n];
        }        
        int currMax = 0;
        for (int i = 1; i < n; i++) {
            currMax = max(currMax, backtrack(n - i) * i);
            currMax = max(currMax, (n - i) * i);
        }
        mem[n] = currMax;
        return mem[n];
    }
};

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);        
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {            
            for (int j = 1; j < i; j++) {                
                dp[i] = max(dp[i], max(dp[j], j) * (i - j));
            }
        }
        return dp[n];
    }
};