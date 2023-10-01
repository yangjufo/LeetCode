class Solution {
public:
    string reverseWords(string s) {
        s += ' ';
        string res, curr;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                reverse(curr.begin(), curr.end());
                res += curr + " ";
                curr.clear();
            } else {
                curr += s[i];
            }
        }
        return res.substr(0, res.length() - 1);
    }
};