class Solution {
public:
    int nthUglyNumber(int n) {        
        vector<int> factors = {2, 3, 5};
        int count = 1;
        unordered_set<int> visited;
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(1);
        visited.insert(1);
        while (count < n) {
            int curr = pq.top();
            count++;
            pq.pop();
            for (int f : factors) {
                if (INT_MAX / f >= curr && visited.find(f * curr) == visited.end()) {
                    visited.insert(f * curr);
                    pq.push(f * curr);
                }
            }
        }
        return pq.top();
    }
};

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        vector<int> dp(n);
        dp[0] = 1;
        int i2 = 0, i3 = 0, i5= 0;
        for (int i = 1; i < n; i++) {
            dp[i] = min(dp[i2] * 2, min(dp[i3] * 3, dp[i5] * 5));
            if (dp[i] == dp[i2] * 2) i2++;
            if (dp[i] == dp[i3] * 3) i3++;
            if (dp[i] == dp[i5] * 5) i5++;
        }
        return dp[n - 1];
    }
};