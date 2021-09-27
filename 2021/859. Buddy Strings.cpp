class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length()) return false;
        int diff1 = -1, diff2 = -1;
        vector<int> count(26, 0);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != goal[i]) {
                if (diff1 == -1) {
                    diff1 = i;
                } else if (diff2 == -1) {
                    diff2 = i;
                } else {
                    return false;
                }
            } else {
                count[s[i] - 'a']++;
            }
        }
        if (diff1 == -1) {
            for (int i = 0; i < 26; i++) {
                if (count[i] >= 2) return true;
            }
            return false;
        }
        if (diff2 == -1) {
            return false;
        }
        return s[diff1] == goal[diff2] && s[diff2] == goal[diff1];
    } 
};