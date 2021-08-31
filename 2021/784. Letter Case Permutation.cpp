class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> curr;
        curr.push_back("");
        for (int i = 0; i < S.length(); i++) {
            vector<string> tmp;            
            for (string& c : curr) {
                tmp.push_back(c + S[i]);
                if (S[i] >= 'a' && S[i] <= 'z') {                    
                    tmp.push_back(c + string(1, S[i] + 'A' - 'a'));
                }
                if (S[i] >= 'A' && S[i] <= 'Z') {
                    tmp.push_back(c + string(1, S[i] + 'a' - 'A'));
                }
            }
            curr = tmp;
        }
        
        return curr;        
    }
};

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        backtrack(s, 0, res);
        return res;
    }
    
    void backtrack(string& s, int index, vector<string>& res) {
        if (index >= s.length()) {
            res.push_back(s);
            return;
        }        
        backtrack(s, index + 1, res);
        if (s[index] >= 'a' && s[index] <= 'z') {            
            s[index] = s[index] - 'a' + 'A';
            backtrack(s, index + 1, res);
        } else if (s[index] >= 'A' && s[index] <= 'Z') {
            s[index] = s[index] - 'A' + 'a';
            backtrack(s, index + 1, res);
        }
    }
};