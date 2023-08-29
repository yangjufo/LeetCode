class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0, curr = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (curr != 0) {
                    length = curr;
                }
                curr = 0;
            } else {
                curr+=1;
            }
        }
        return curr == 0 ? length : curr;
    }
};