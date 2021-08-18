class Solution {
public:
    string reverseStr(string s, int k) {
        int start = 0;
        while (start < s.length()) {
            reverse(s.begin() + start, s.begin() + min((int)s.length(), start + k));            
            start += 2 * k;
        }
        return s;
    }
};