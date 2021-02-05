class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(0, 0, n, "", res);
        return res;        
    }
    
    void backtrack(int left, int right, int n, string current, vector<string>& res) {
        if (left == n && right == n) {
            res.push_back(current);
            return;
        }
        
        if (left < n) {
            backtrack(left + 1, right, n, current + "(", res);            
        }
        
        if (right < left) {
            backtrack(left, right + 1, n, current + ")", res);
        }
        
    }
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack("", n, 0, 0, res);
        return res;
    }
    
    void backtrack(string curr, int n, int left, int right, vector<string>& res) {
        if (left == n && right == n) {
            res.push_back(curr);
            return;
        }
        
        if (right < left) {            
            backtrack(curr + ")", n, left, right + 1, res);
            
        }
        if (left < n) {
            backtrack(curr + "(", n, left + 1, right, res);
        }
    }
};