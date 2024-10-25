class Solution {
public:
    int calculate(string s) {
        stack<int> numStack;
        char op = '+';
        int num = 0, lastNum = 0, ans = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            if ((!isdigit(c) && c != ' ') || i + 1 == s.length()) {
                if (op == '+' || op == '-') {
                    ans += lastNum;
                    lastNum = op == '+' ? num : -num;
                } else if (op == '*') {
                    lastNum = lastNum * num;
                } else if (op == '/') {
                    lastNum = lastNum / num;
                }
                op = c;
                num = 0;
            }
        }
        return ans + lastNum;
    }
};