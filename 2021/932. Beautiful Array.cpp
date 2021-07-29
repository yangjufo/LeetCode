class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> res = {1};
        while (res.size() < n) {
            vector<int> tmp;
            for (int i : res) {
                if (2 * i - 1 <= n) {
                    tmp.push_back(2 * i - 1);
                }
            }
            for (int i : res) {
                if (2 * i <= n) {
                    tmp.push_back(2 * i);
                }
            }
            res = tmp;
        }
        return res;
    }
};

class Solution {
public:
    unordered_map<int, vector<int>> mem;
    vector<int> beautifulArray(int n) {
        return helper(n);
    }
    
    vector<int> helper(int n) {
        if (mem.find(n) != mem.end()) {
            return mem[n];
        }
        vector<int> res;
        if (n == 1) {
            res.push_back(1);
        } else {            
            for (int x : helper((n + 1) / 2)) {
                res.push_back(2 * x - 1);
            }
            for (int x : helper(n / 2)) {
                res.push_back(2 * x);
            }
        }
        mem[n] = res;
        return mem[n];
    }
};