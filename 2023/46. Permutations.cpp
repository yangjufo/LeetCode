class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(nums, 0, res);
        return res;
    }

    void helper(vector<int> nums, int index, vector<vector<int>>& res) {
        if (index == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            helper(nums, index + 1, res);
        }
    }
};