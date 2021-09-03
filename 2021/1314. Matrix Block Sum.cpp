class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> preSum(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                preSum[i + 1][j + 1] = mat[i][j] + preSum[i][j + 1] + preSum[i + 1][j] - preSum[i][j];
            }
        }
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = preSum[min(i + k + 1, m)][min(j + k + 1, n)] - preSum[max(0, i - k)][min(j + k + 1, n)] - preSum[min(i + k + 1, m)][max(0, j - k)] + preSum[max(0, i - k)][max(0, j - k)];
            }
        }
        return res;
    }
};