class Solution {
public:
    void expand(string s, int l, int r, int& max_len, int& max_st) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            if (r - l + 1 > max_len) {
                max_st = l;
                max_len = r - l + 1;
            }
            l--;
            r++;
        }
    }
    string longestPalindrome(string s) {
        int max_len = 0, max_st = 0;
        for (int i = 0; i < s.length(); i++) {
            expand(s, i, i, max_len, max_st);
            expand(s, i, i + 1, max_len, max_st);
        }
        return s.substr(max_st, max_len);
    }
};