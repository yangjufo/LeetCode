class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> current;
        
        backtrack(nums, 0, current, res);
        
        return res;
    }
    
    void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& res) {
        if (current.size() == nums.size()) {
            res.push_back(current);
            return;
        }
        
        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);
            swap(nums, start, i);
            backtrack(nums, start + 1, current, res);
            swap(nums, i, start);
            current.pop_back();
        }
    }
    
    void swap(vector<int>& nums, int left, int right) {
        if (left == right) return;
        
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, 0, res);
        return res;
    }
    
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& res) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }        
        
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            backtrack(nums, start + 1, res);
            swap(nums[start], nums[i]);
        }
    }
};
