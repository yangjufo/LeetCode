class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        backtrack(candidates, 0, curr, 0, target);
        return res;
    }
    
    void backtrack(vector<int>& candidates, int start, vector<int>& curr, int sum, int target) {
        if (sum >= target) {
            if (sum == target) {
                res.push_back(curr);
            }
            return;
        }             
        for (int i = start; i < candidates.size(); i++) {
            if (i != start && candidates[i] == candidates[i - 1]) continue;
            curr.push_back(candidates[i]);
            backtrack(candidates, i + 1, curr, sum + candidates[i], target);
            curr.pop_back();
        }
    }
};