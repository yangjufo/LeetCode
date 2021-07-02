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

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res = {0, 1};        
        for (int i = 2; i <= n; i++) {
            int size = res.size();
            for (int j = size - 1; j >= 0; j--) {
                res.push_back(res[j] | (1 << i - 1));
            }
        }
        return res;
    }
};