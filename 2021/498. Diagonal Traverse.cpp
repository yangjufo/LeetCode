class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = (m == 0) ? 0 : matrix[0].size();
        bool up = true;
        for (int sum = 0; sum <= m + n - 2; sum++) {
            if (up) {
                int i = (sum >= m) ? m - 1 : sum;
                int j = sum - i;
                while (i >= 0 && j < n) {
                    res.push_back(matrix[i][j]);
                    i -= 1;
                    j += 1;
                }                
            } else {
                int j = (sum >= n) ? n - 1 : sum;
                int i = sum - j;
                while (i < m && j >= 0) {
                    res.push_back(matrix[i][j]);
                    i += 1;
                    j -= 1;
                }
            }
            up = !up;
        }
        return res;
    }
};