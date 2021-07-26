class Solution {
public:
    int findIntegers(int n) {              
        if (n == 0) return 1;
        return 1 + dfs(n, 1);
    }
    
    int dfs(int n, int num) {
        if (num > n) return 0;
        if (num == n) return 1;
        if ((num & 0x1) == 1) {
            return 1 + dfs(n, (num << 1) + 0);
        }
        return 1 + dfs(n, (num << 1) + 1) + dfs(n, (num << 1) + 0);
    }
};

class Solution {
public:
    int findIntegers(int n) {
        int f[32];
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < 32; ++i)
            f[i] = f[i-1]+f[i-2];
        int ans = 0, k = 30, pre_bit = 0;
        while (k >= 0) {
            if (n&(1<<k)) {
                ans += f[k];
                if (pre_bit) return ans;
                pre_bit = 1;
            }
            else
                pre_bit = 0;
            --k;
        }
        return ans+1;
    }
};