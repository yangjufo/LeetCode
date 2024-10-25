class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if (nums.empty()) {
            return {{lower, upper}};
        }
        vector<vector<int>> res;
        if (nums[0] > lower) {
            res.push_back({lower, nums[0] - 1});
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] != 1) {
                res.push_back({nums[i - 1] + 1, nums[i] - 1});
            }
        }
        if (nums.back() < upper) {
            res.push_back({nums.back() + 1, upper});
        }
        return res;
    }
};