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

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {    
        int pn = primes.size();
        vector<int> pIndexes(pn, 0), nums = { 1 };
        for (int i = 1; i < n; i++) {
            int next = INT_MAX;
            for (int j = 0; j < pn; j++) {
                next = min(next, nums[pIndexes[j]] * primes[j]);                
            }
            for (int j = 0; j < pn; j++) {
                if (next == nums[pIndexes[j]] * primes[j]) {
                    pIndexes[j]++;
                }
            }
            nums.push_back(next);
        }
        return nums[n - 1];
        
    }
};