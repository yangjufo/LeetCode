class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> taken(nums.size(), false);
        vector<int> curr;
        vector<vector<int>> res;
        backtrack(nums, taken, nums.size(), curr, res);
        return res;
    }

    void backtrack(vector<int>& nums, vector<bool>& taken, int count,
                   vector<int>& curr, vector<vector<int>>& res) {
        if (count == 0) {
            res.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!taken[i]) {
                curr.push_back(nums[i]);
                taken[i] = true;
                backtrack(nums, taken, count - 1, curr, res);
                taken[i] = false;
                curr.pop_back();
            }
        }
    }
};