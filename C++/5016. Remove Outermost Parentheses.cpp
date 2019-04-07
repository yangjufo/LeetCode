class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        vector<char> pStack;
        string tmp;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') { 
                if (!pStack.empty())
                    tmp += "(";
                pStack.push_back(s[i]);            
            }
            if (s[i] == ')') {
                pStack.pop_back();
                if (!pStack.empty())
                    tmp += ")";
                else {
                    res += tmp;
                    tmp = "";
                }
            }
        }
        return res;
    }
};