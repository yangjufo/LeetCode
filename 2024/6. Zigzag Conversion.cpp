class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int row = 0, flag = -1;
        vector<string> sr(numRows);
        for (char c : s) {
            sr[row] += c;
            if (row == 0) {
                flag = 1;
            }
            if (row == numRows - 1) {
                flag = -1;
            }
            row += flag;
        }
        string res;
        for (string& rs : sr) {
            res += rs;
        }
        return res;
    }
};

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string res;
        int charsInSection = (numRows - 1) * 2;
        for (int row = 0; row < numRows; row++) {
            int index = row;
            while (index < s.length()) {
                res += s[index];
                if (row != 0 && row != numRows - 1) {
                    int charsInBetween = charsInSection - 2 * row;
                    int secondIndex = index + charsInBetween;
                    if (secondIndex < s.length()) {
                        res += s[secondIndex];
                    }
                }
                index += charsInSection;
            }
        }
        return res;
    }
};