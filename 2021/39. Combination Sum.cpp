class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> current;
        backtrack(candidates, 0, current, target, res);
        return res;
    }
    
    void backtrack(vector<int>& candidates, int start, vector<int>& current, int target, vector<vector<int>>& res) {
        if (target == 0) {            
            res.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size() && candidates[i] <= target; i++) {
            current.push_back(candidates[i]);
            backtrack(candidates, i, current, target - candidates[i], res);
            current.pop_back();            
        }
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> res;
        backtrack(candidates, 0, target, curr, res);
        return res;
    }
    
    void backtrack(vector<int>& candidates, int start, int target, vector<int>& curr, vector<vector<int>>& res) {
        if (target <= 0) {
            if (target == 0) {
                res.push_back(curr);
            }
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            backtrack(candidates, i, target - candidates[i], curr, res);
            curr.pop_back();
        }
    }
};