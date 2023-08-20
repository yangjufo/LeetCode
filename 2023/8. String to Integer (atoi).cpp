class Solution {
public:
    int myAtoi(string s) {
        int i = 0, num = 0, sign = 1, intFound = false;
        while (i < s.length() && s[i] == ' ') {
            i++;
        }
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '+') ? 1 : -1;
            i++;
        }

        while (i < s.length()) {
            if (!isdigit(s[i])) {
                return intFound ? num : 0;
            }
            intFound = true;
            int tmp = sign * (s[i] - '0');
            if (sign > 0 && (INT_MAX - tmp) / 10 < num) {
                return INT_MAX;
            }
            if (sign < 0 && (INT_MIN - tmp) / 10 > num) {
                return INT_MIN;
            }
            num = num * 10 + tmp;
            i++;
        }
        return num;
    }
};