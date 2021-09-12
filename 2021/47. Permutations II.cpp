class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return res;
    }
    
    void backtrack(vector<int> nums, int start) {
        if (start == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            if (i != start && nums[i] == nums[start]) continue;                        
            swap(nums[i], nums[start]);
            backtrack(nums, start + 1);
        }        
    }
};

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<bool>> visited;
    vector<bool> taken;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        visited.resize(n, vector<bool>(21, false));
        taken.resize(n, false);
        vector<int> curr;
        backtrack(nums, curr);
        return res;
    }
    
    void backtrack(vector<int>& nums, vector<int>& curr) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[curr.size()][nums[i] + 10] || taken[i]) continue;
            visited[curr.size()][nums[i] + 10] = true;
            taken[i] = true;
            curr.push_back(nums[i]);
            backtrack(nums, curr);
            curr.pop_back();
            taken[i] = false;
        }
        for (int i = 0; i < 21; i++) {
            visited[curr.size()][i] = false;
        }
    }
};

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        backtrack(nums, 0, res);
        return res;
    }
    
    void backtrack(vector<int> nums, int index, vector<vector<int>> &res) {
        if (index >= nums.size()) {
            res.push_back(nums);
        }
        for (int i = index; i < nums.size(); i++) {
            if (i != index && nums[i] == nums[index]) {
                continue;
            }
            swap(nums[index], nums[i]);
            backtrack(nums, index + 1, res);
        }
    }    
};