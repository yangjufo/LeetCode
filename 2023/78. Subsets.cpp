class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, 0, {}, res);
        return res;
    }

    void backtrack(vector<int>& nums, int index, vector<int> curr, vector<vector<int>>& res) {
        res.push_back(curr);
        for (int i = index; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            backtrack(nums, i + 1, curr, res);
            curr.pop_back();
        }
    }
};