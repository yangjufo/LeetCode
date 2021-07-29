class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return helper(n, n);
    }
    
    vector<string> helper(int n, int len) {
        if (n == 0) return vector<string> {""};
        if (n == 1) return vector<string> {"0", "1", "8"};
        
        vector<string> sub = helper(n - 2, len);
        vector<string> res;
        
        for (string s : sub){
            if (n != len) {
                res.push_back("0" + s + "0");
            }
            res.push_back("1" + s + "1");
            res.push_back("6" + s + "9");
            res.push_back("8" + s + "8");
            res.push_back("9" + s + "6");
        }
        
        return res;
    }
};


class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return build(n, n);
    }
    
    vector<string> build(int m, int n) {
        if (m == 0) {
            return {""};
        }        
        if (m == 1) {
            return {"0", "1", "8"};
        }        
        vector<string> smaller = build(m - 2, n), res;        
        for (string s : smaller) {
            if (m != n) {
                res.push_back("0" + s + "0");
            }
            res.push_back("1" + s + "1");
            res.push_back("6" + s + "9");
            res.push_back("8" + s + "8");
            res.push_back("9" + s + "6");
        }
        return res;
    }
};