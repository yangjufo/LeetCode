class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<int> dp = matrix[0];
        for (int i = 1; i < matrix.size(); i++) {
            vector<int> tmp = dp;
            for (int j = 0; j < matrix[i].size(); j++) {
                dp[j] += matrix[i][j];
                if (j > 0) {
                    dp[j] = min(dp[j], tmp[j - 1] + matrix[i][j]);
                }
                if (j + 1< matrix[i].size()) {
                    dp[j] = min(dp[j], tmp[j + 1] + matrix[i][j]);
                }
            }
        }
        int res = INT_MAX;
        for (int n : dp) {
            res = min(res, n);
        }
        return res;

    }
};