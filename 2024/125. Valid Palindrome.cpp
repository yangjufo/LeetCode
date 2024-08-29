class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            while (i < j && !((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))) {
                i++;
            }
            if (i < j && s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = s[i] - 'A' + 'a';
            }
            while (i < j && !((s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9'))) {
                j--;
            }
            if (i < j && s[j] >= 'A' && s[j] <= 'Z') {
                s[j] = s[j] - 'A' + 'a';
            }
            if (i < j && s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};