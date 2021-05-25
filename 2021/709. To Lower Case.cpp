class Solution {
public:
    string toLowerCase(string s) {
        string res;
        for (char c : s) {
            if (c >= 'A' && c <= 'Z') {
                res += c -'A' + 'a';
            } else {
                res += c;
            }            
        }
        return res;
    }
};