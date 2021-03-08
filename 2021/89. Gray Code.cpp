class Solution {
public:    
    vector<int> grayCode(int n) {
        vector<int> res;
        backtrack(n, res);
        return res;
    }
    
    void backtrack(int n, vector<int>& res) {
        if (n == 1) {
            res.push_back(0);
            res.push_back(1);
            return;
        }
        backtrack(n - 1, res);
        int size = res.size();
        for (int i = size - 1; i >= 0; i--) {
            res.push_back(res[i] | (1 << (n - 1)));
        }
    }
};