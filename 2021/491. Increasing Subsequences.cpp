class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> res;
        unordered_set<string> visited;        
        backtrack(nums, 0, curr, res, "", visited);
        return res;
    }
    
    void backtrack(vector<int>& nums, int index, vector<int>& curr, vector<vector<int>>& res, string num, unordered_set<string>& visited) {
        if (curr.size() >= 2 && visited.find(num) == visited.end()) {            
            res.push_back(curr);
        }        
        visited.insert(num);
        for (int i = index; i < nums.size(); i++) {
            if (i != index && nums[i] == nums[i - 1]) {
                continue;
            }
            if (curr.empty() || nums[i] >= curr.back()) {
                curr.push_back(nums[i]);
                backtrack(nums, i + 1, curr, res, num + "#" + to_string(nums[i]), visited);
                curr.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> res;          
        backtrack(nums, 0, curr, res);
        return res;
    }
    
    void backtrack(vector<int>& nums, int index, vector<int>& curr, vector<vector<int>>& res) {
        if (curr.size() >= 2) {            
            res.push_back(curr);
        }        
        unordered_set<int> used;
        for (int i = index; i < nums.size(); i++) {
            if (used.find(nums[i]) != used.end()) {
                continue;
            }
            used.insert(nums[i]);
            if (curr.empty() || nums[i] >= curr.back()) {
                curr.push_back(nums[i]);
                backtrack(nums, i + 1, curr, res);
                curr.pop_back();
            }
        }
    }
};