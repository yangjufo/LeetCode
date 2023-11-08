class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != goal[0]) {
                continue;
            }
            int j = 0;
            while (j < goal.length() && s[(i + j) % s.length()] == goal[j]) {
                j++;
            }
            if (j >= goal.length()) {
                return true;
            }
        }
        return false;
    }
};