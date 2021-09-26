class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> preSum(n, 0), postSum(n, 0);
        for (int j = 0; j < n; j++) {
            preSum[j] = (long long)grid[1][j] + (j == 0 ? 0 : preSum[j - 1]);
        }
        for (int j = n - 1; j >= 0; j--) {
            postSum[j] = (long long)grid[0][j] + (j == n - 1 ? 0 : postSum[j + 1]);
        }
        long long minSum = preSum.back() + postSum[0];
        for (int j = 0; j < n; j++) {
            long long curr = 0;
            if (j > 0) {
                curr = max(curr, preSum[j - 1]);
            }
            if (j + 1 < n) {
                curr = max(curr, postSum[j + 1]);
            }
            minSum = min(minSum, curr);
        }
        return minSum;
    }
};