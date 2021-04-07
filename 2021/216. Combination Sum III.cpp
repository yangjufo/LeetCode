class Solution {
public:
    vector<vector<int>> combs;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        backtrack(curr, 1, 0, k, n);
        return combs;
    }
    
    void backtrack(vector<int> curr, int start, int sum, int k, int n) {    
        if (sum == n && curr.size() == k) {
            combs.push_back(curr);
            return;
        }        
        if (sum > n || start > 9 || curr.size() > k) return;
        backtrack(curr, start + 1, sum, k, n);
        curr.push_back(start);
        backtrack(curr, start + 1, sum + start, k, n);
    }
};

class Solution {
public:
    vector<vector<int>> combs;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        backtrack(curr, 1, k, n);
        return combs;
    }
    
    void backtrack(vector<int>& curr, int start, int k, int n) {    
        if (n == 0 && curr.size() == k) {
            combs.push_back(curr);
            return;
        }        
        if (n < 0 || curr.size() == k) return;
        for (int i = start; i <= 9; i++) {
            curr.push_back(i);
            backtrack(curr, i + 1, k, n - i);
            curr.pop_back();
        }
    }
};