class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> getFactors(int n) {
        vector<int> curr;
        backtrack(n, curr, 2);
        return res;
    }
    
    void backtrack(int n, vector<int>& curr, int start) {        
        if (n <= 1) {             
            if (curr.size() > 1) {
                res.push_back(curr);  
            }
        }
        
        for (int i = start; i <= n; i++) {
            if (n % i == 0) {
                curr.push_back(i);
                backtrack(n / i, curr, i);
                curr.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> getFactors(int n) {
        vector<int> curr;
        backtrack(n, curr, 2);
        return res;
    }
    
    void backtrack(int n, vector<int>& curr, int start) {                       
        for (int i = start; i <= n / i; i++) {
            if (n % i == 0) {                
                curr.push_back(i);
                curr.push_back(n / i);
                res.push_back(curr);
                curr.pop_back();
                backtrack(n / i, curr, i);
                curr.pop_back();
            }
        }
    }
};


class Solution {
public:
    vector<vector<int>> res;    
    vector<vector<int>> getFactors(int n) {
        vector<int> curr;
        backtrack(n, curr, n - 1);
        return res;
    }
    
    void backtrack(int n, vector<int>& curr, int last) {
        if (n == 1) {
            if (!curr.empty()) {
                res.push_back(curr);
            }
            return;
        }
        for (int i = 2; i <= last && i <= n; i++) {
            if (n % i == 0) {
                curr.push_back(i);
                backtrack(n / i, curr, i);
                curr.pop_back();
            }
        }
    }
};