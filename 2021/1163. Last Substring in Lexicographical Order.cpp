class Solution {
public:
    string lastSubstring(string s) {
        int i = 0, j = 1, k = 0;
        while (j + k < s.length()) {
            if (s[i + k] == s[j + k]) {
                k++;
            } else if (s[i + k] > s[j + k]) {
                j = j + k + 1;
                k = 0;
            } else {
                i = i + k + 1;                
                k = 0;
            }
            if (i == j) {
                j = j + 1;
            }
        }
        return s.substr(i);
    }
};