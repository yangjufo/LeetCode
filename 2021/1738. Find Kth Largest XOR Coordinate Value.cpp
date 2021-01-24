class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        priority_queue <int, vector<int>, greater<int> > pq;
        int dp[n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < m; i++) {
            int curr = 0;
            for (int j = 0; j < n; j++) {
                curr ^= matrix[i][j];
                dp[j] = dp[j] ^ curr;
                pq.push(dp[j]);
                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};