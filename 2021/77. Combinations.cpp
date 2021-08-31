class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        backtrack(curr, 1, n, k);
        return res;
    }
    
    void backtrack(vector<int>& curr, int start, int n, int k) {
        if (curr.size() == k) {
            res.push_back(curr);
            return;
        }
        for (int i = start; i <= n; i++) {
            curr.push_back(i);
            backtrack(curr, i + 1, n, k);
            curr.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        vector<vector<int>> res;
        backtrack(n, 1, k, curr, res);
        return res;
    }
    
    void backtrack(int n, int index, int k, vector<int>& curr, vector<vector<int>>& res) {
        if (curr.size() >= k) {
            res.push_back(curr);
            return;
        }            
        
        for (int i = index; i <= n; i++) {
            curr.push_back(i);
            backtrack(n, i + 1, k, curr, res);
            curr.pop_back();
        }
        
    }
};