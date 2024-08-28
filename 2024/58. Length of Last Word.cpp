class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        while (i >= 0 && s[i] == ' ') {
            i -= 1;
        }
        int end = i;
        while (i >= 0) {
            if (s[i] == ' ') {
                break;
            }
            i--;
        }
        return end - i;
    }
};