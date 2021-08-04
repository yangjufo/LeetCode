class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> current;
        backtrack(nums, 0, current, res);
        return res;
    }
    
    void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& res) {
        res.push_back(current);        
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, res);
            current.pop_back();            
        }
    }
};

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        backtrack(nums, 0, curr);
        return res;
    }
    
    void backtrack(vector<int>& nums, int index, vector<int>& curr) {
        res.push_back(curr);
        for (int i = index; i < nums.size(); i++) {
            if (i != index && nums[i] == nums[i - 1]) continue;
            curr.push_back(nums[i]);
            backtrack(nums, i + 1, curr);
            curr.pop_back();
        }
    }
};