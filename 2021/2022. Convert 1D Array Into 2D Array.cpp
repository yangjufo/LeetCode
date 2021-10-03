class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()) return {};
        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            res.push_back({});
            for (int j = 0; j < n; j++) {
                res.back().push_back(original[n * i + j]);
            }
        }
        return res;
    }
};