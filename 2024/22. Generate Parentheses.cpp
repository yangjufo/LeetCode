class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string curr;
        vector<string> res;
        backtrack(curr, 0, 0, n, res);
        return res;
    }

    void backtrack(string& curr, int open, int close, int n, vector<string>& res) {
        if (open == close && open == n) {
            res.push_back(curr);
            return;
        }
        if (open > n) {
            return;
        }
        if (open > close) {
            curr += ')';
            backtrack(curr, open, close + 1, n, res);
            curr.pop_back();
        }
        if (open < n) {
            curr += '(';
            backtrack(curr, open + 1, close, n, res);
            curr.pop_back();
        }
    }
};