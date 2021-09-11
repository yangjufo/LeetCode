class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {        
        vector<vector<int>> res;
        vector<int> current;
        backtrack(nums, 0, current, res);
        return res;
    }
    
    void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& res) {
        res.push_back(current);
        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, res);
            current.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> res;
        backtrack(nums, 0, curr, res);
        return res;
    }
    
    void backtrack(vector<int>& nums, int start, vector<int>& curr, vector<vector<int>>& res) {
        res.push_back(curr);
        for (int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            backtrack(nums, i + 1, curr, res);
            curr.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> res;
        backtrack(0, nums, curr, res);
        return res;
    }
    
    void backtrack(int index, vector<int>& nums, vector<int>& curr, vector<vector<int>>& res) {
        if (index >= nums.size()) {
            res.push_back(curr);
            return;
        }       
        backtrack(index + 1, nums, curr, res);
        curr.push_back(nums[index]);
        backtrack(index + 1, nums, curr, res);
        curr.pop_back();
    }
};