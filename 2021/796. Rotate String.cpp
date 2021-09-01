class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == goal[0]) {
                int j = i, k = 0;
                while (k < goal.length() && (s[j % s.length()] == goal[k])) {
                    k++;
                    j++;
                }
                if (k >= goal.length()) {
                    return true;
                }
            }            
        }
        return false;
    }
};

class Solution {
public:
    bool rotateString(string A, string B) {
        return A.size() == B.size() && (A + A).find(B) != string::npos;
    }
};