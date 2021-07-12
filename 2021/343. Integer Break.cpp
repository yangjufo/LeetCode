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