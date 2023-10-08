class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        vector<vector<int>> res;
        backtrack(curr, 0, k, n, 1, res);
        return res;
    }

    void backtrack(vector<int>& curr, int sum, int k, int n, int start, vector<vector<int>>& res) {
        if (sum == n) {
            if (curr.size() == k) {
                res.push_back(curr);
            }
            return;
        }
        for (int i = start; i <= 9; i++) {
            curr.push_back(i);
            backtrack(curr, sum + i, k, n, i + 1, res);
            curr.pop_back();
        }
    }
};