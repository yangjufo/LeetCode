class Solution {
public:
    string truncateSentence(string s, int k) {
        int index = 0;
        while (index < s.length()) {
            if (s[index] == ' ') {
                k--;
            }
            if (k <= 0) {
                break;
            }
            index++;
        }
        return s.substr(0, index);
    }
};