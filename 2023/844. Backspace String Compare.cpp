class Solution {
public:
    string getStr(string s) {
        string rs;
        int is = -1;
        for (char c : s) {
            if (c == '#') {
                if (is > -1) {
                    is--;
                }
            } else {
                if (is == -1) {
                    is = 0;
                }
                if (rs.size() <= is) {
                    rs += c;
                } else {
                    rs[is] = c;
                }
                is++;
            }
        }
        if (is <= 0) return "";
        return rs.substr(0, is);
    }
    bool backspaceCompare(string s, string t) {
        return getStr(s) == getStr(t);
    }
};