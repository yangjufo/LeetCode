class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> preSum(n, 0);
        for (int i = 0; i < n; i++) {
            preSum[i] = (i == 0) ? stones[i] : preSum[i - 1] + stones[i];
        }
        int mx = preSum.back(), ans = INT_MIN;
        for (int i = n - 2; i >= 0; --i) {
            ans = max(ans, mx); // since dp[i] = mx, we try to use dp[i] to update ans.
            mx = max(mx, preSum[i] - mx); // try to update mx using prefix[i] - dp[i]
        }
        return ans;
    }
};