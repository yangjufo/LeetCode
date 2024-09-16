class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        vector<vector<int>> res;
        backtrack(1, n, k, curr, res);
        return res;
    }

    void backtrack(int start, int n, int k, vector<int>& curr, vector<vector<int>>& res) {
        if (k == 0) {
            res.push_back(curr);
            return;
        }
        for (int i = start; i <= n; i++) {
            curr.push_back(i);
            backtrack(i + 1, n, k - 1, curr, res);
            curr.pop_back();
        }
    }
};