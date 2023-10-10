class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        vector<vector<int>> res;
        backtrack(curr, n, 1, k, res);
        return res;
    }

    void backtrack(vector<int>& curr, int n, int start, int k, vector<vector<int>>& res) {
        if (curr.size() == k) {
            res.push_back(curr);
            return;
        }
        for (int i = start; i <= n; i++) {
            curr.push_back(i);
            backtrack(curr, n, i + 1, k, res);
            curr.pop_back();
        }
    }
};