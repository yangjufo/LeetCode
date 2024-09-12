class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        for (int r = 0; r <= min(m - 1, n - 1) / 2; r++) {
            for (int j = r; j < n - r; j++) {
                res.push_back(matrix[r][j]);
            }
            for (int i = r + 1; i < m - r; i++) {
                res.push_back(matrix[i][n - r - 1]);
            }
            for (int j = n - r - 2; j >= r && m - r - 1 > r; j--) {
                res.push_back(matrix[m - r - 1][j]);
            }
            for (int i = m - r - 2; i > r && r < n - r - 1; i--) {
                res.push_back(matrix[i][r]);
            }
        }
        return res;
    }
};