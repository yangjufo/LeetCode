class Solution {
public:
    int calculate(string s) {
        stack<int> numStack;
        int ans = 0;
        int sign = 1;
        int num = 0;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+') {                
                ans += sign * num;
                sign = 1;
                num = 0;
            } else if (c == '-') {
                ans += sign * num;
                sign = -1;
                num = 0;
            } else if (c == '(') {
                numStack.push(ans);
                numStack.push(sign);
                
                sign = 1;
                ans=0;
            } else if (c == ')') {
                ans += sign * num;
                ans *= numStack.top();
                numStack.pop();
                ans += numStack.top();
                numStack.pop();
                num = 0;
            }            
        }
        return ans + sign * num;
    }
};