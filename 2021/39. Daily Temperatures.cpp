class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int, int>> tStack;
        vector<int> res(T.size(), 0);
        for (int i = 0; i < T.size(); i++) {
            while (!tStack.empty() && T[i] > tStack.top().first) {
                res[tStack.top().second] = i - tStack.top().second;
                tStack.pop();
            }
            tStack.push({T[i], i});
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(candidates, curr, res, 0, target);
        return res;
    }
    
    void backtrack(vector<int>& candidates, vector<int>& curr, vector<vector<int>>& res, int index, int target) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }        
        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] <= target) {
                curr.push_back(candidates[i]);
                backtrack(candidates, curr, res, i, target - candidates[i]);
                curr.pop_back();
            }
        }
    }
};