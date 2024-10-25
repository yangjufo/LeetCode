class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size();
        vector<array<int, 3>> tuples;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                // sum, row, val
                tuples.push_back({i + j, i, nums[i][j]});
            }
        }
        sort(tuples.begin(), tuples.end(), [](array<int, 3>& left, array<int, 3>& right) {
            return left[0] == right[0] ? left[1] > right[1] : left[0] < right[0];
        });
        vector<int> res;
        for (auto& t : tuples) {
            res.push_back(t[2]);
        }
        return res;
    }
};