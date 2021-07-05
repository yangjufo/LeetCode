class Solution {
public:
    int mod = 1'000'000'007;
    int countVowelPermutation(int n) {        
        vector<int> dp(5, 1);
        for (int i = 1; i < n; i++) {
            vector<int> next(5, 0);
            next[0] = ((dp[1] + dp[2]) % mod + dp[4]) % mod;
            next[1] = (dp[0] + dp[2]) % mod;
            next[2] = (dp[1] + dp[3]) % mod;
            next[3] = dp[2];
            next[4] = (dp[2] + dp[3]) % mod;
            dp = next;
        }
        int total = 0;
        for (int i = 0; i < 5; i++) {
            total = (total + dp[i]) % mod;
        }
        return total;
    }
};