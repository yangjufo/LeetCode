class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string strN = to_string(n);
        int marker = strN.length();
        for (int i = strN.length() - 1; i > 0; i--) {
            if (strN[i] < strN[i - 1]) {
                marker = i;
                strN[i - 1]--;                
            }
        }
        for (int i = marker; i < strN.length(); i++) {
            strN[i] = '9';
        }
        return stoi(strN);
    }
};

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string strN = to_string(n);
        int marker = strN.length();
        for (int i = (int)strN.length() - 1; i > 0; i--) {
            if (strN[i] < strN[i - 1]) {
                marker = i;
                strN[i - 1]--;
            }
        }
        for (int i = marker; i < strN.length(); i++) {
            strN[i] = '9';
        }
        return stoi(strN);
    }
};