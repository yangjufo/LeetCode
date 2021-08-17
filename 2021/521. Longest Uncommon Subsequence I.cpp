class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a.length() != b.length()) return max(a.length(), b.length());
        int i = 0;
        while (i < a.length() && a[i] == b[i]) {
            i++;
        }
        return i >= a.length() ?- 1 : a.length();
    }
};