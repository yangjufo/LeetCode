class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> res;
        backtrack(candidates, 0, target, curr, res);
        return res;
    }

    void backtrack(vector<int>& candidates, int start, int target,
                   vector<int>& curr, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            backtrack(candidates, i, target - candidates[i], curr, res);
            curr.pop_back();
        }
    }
};