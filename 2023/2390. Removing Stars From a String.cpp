class Solution {
public:
    string removeStars(string s) {
        string rs;
        int is = 0;
        for (char c : s) {
            if (c == '*') {
                is--;
            } else {
                if (rs.length() <= is) {
                    rs += c;
                } else {
                    rs[is] = c;
                }
                is++;
            }
        }
        return rs.substr(0, is);
    }
};