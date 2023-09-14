class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        helper(nums, 0, res);
        return res;
    }

    void helper(vector<int> nums, int index, vector<vector<int>>& res) {
        if (index == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[index]) {
                continue;
            }
            swap(nums[i], nums[index]);
            helper(nums, index + 1, res);
        }
    }
};