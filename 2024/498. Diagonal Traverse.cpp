class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res;
        bool up = true;
        for (int sum = 0; sum <= m + n - 2; sum += 1) {
            if (up) {
                int i = (sum >= m) ? m - 1 : sum;
                int j = sum - i;
                while (i >= 0 && j < n) {
                    res.push_back(mat[i][j]);
                    i -= 1;
                    j += 1;
                }
            } else {
                int j = (sum >= n) ? n - 1 : sum;
                int i = sum - j;
                while (j >= 0 && i < m) {
                    res.push_back(mat[i][j]);
                    j -= 1;
                    i += 1;
                }
            }
            up = !up;
        }
        return res;
    }
};