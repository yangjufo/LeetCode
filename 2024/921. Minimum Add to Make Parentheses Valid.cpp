class Solution {
public:
    int minAddToMakeValid(string s) {
        int openCount = 0, adds = 0;
        for (char c : s) {
            if (c == '(') {
                openCount += 1;
            } else if (c == ')') {
                if (openCount > 0) {
                    openCount -= 1;
                } else {
                    adds += 1;
                }
            }
        }
        return openCount + adds;
    }
};