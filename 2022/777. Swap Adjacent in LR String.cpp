class Solution {
public:
    bool canTransform(string start, string end) {
        int countL = 0, countR = 0;
        for (int i = 0; i < start.length(); i++) {
            if (start[i] == 'R') {
                if (countL > 0) {
                    return false;
                }
                countR++;
            }
            if (end[i] == 'R') {
                countR -= 1;
                if (countR < 0) {
                    return false;
                }
            }
            if (end[i] == 'L') {
                if (countR > 0) {
                    return false;
                }
                countL += 1;
            }
            if (start[i] == 'L') {
                countL -= 1;
                if (countL < 0) {
                    return false;
                }
            }
        }
        return countR == 0 && countL == 0;
    }
};

class Solution {
public:
    bool canTransform(string start, string end) {
        int i = 0, j = 0;
        while (i < start.length() && j < end.length()) {
            while (i < start.length() && start[i] == 'X') {
                i++;
            }
            while (j < end.length() && end[j] == 'X') {
                j++;
            }
            if (i < start.length() && j < end.length()) {
                if (start[i] != end[j] || (start[i] == 'L' && i < j) || (start[i] == 'R' && i > j)) {
                    return false;
                }
                i++;
                j++;
            }
        }
        while (i < start.length() && start[i] == 'X') {
            i++;
        }
        while (j < end.length() && end[j] == 'X') {
            j++;
        }
        return i >= start.length() && j >= end.length();
    }
};