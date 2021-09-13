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

class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        backtrack(0, 0, n, "");
        return res;
    }
    
    void backtrack(int open, int close, int n, string curr) {
        if (close >= n) {
            res.push_back(curr);
            return;
        }
        if (open < n) {
            backtrack(open + 1, close, n, curr + "(");            
        }
        if (close < open) {
            backtrack(open, close + 1, n, curr + ")");
        }       
    }
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(0, 0, n, "", res);
        return res;
    }
    
    void backtrack(int openCount, int closeCount, int n, string curr, vector<string>& res) {
        if (openCount == n && closeCount == n) {
            res.push_back(curr);
            return;
        }   
        if (openCount < n) {
            backtrack(openCount + 1, closeCount, n, curr + "(", res);
        }
        if (openCount > closeCount) {
            backtrack(openCount, closeCount + 1, n, curr + ")", res);
        }
    }
};