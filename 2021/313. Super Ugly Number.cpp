class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int prev = 1;
        vector<int> dp(n, 0);        
        vector<int> indexes(primes.size(), 0);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            dp[i] = INT_MAX;
            for (int j = 0; j < primes.size(); j++) {
                dp[i] = min(dp[i], dp[indexes[j]] * primes[j]);                
            }
            for (int j = 0; j < primes.size(); j++) {
                if (dp[i] == dp[indexes[j]] * primes[j]) {
                    indexes[j]++;
                }
            }            
        }
        return dp[n - 1];
    }
};