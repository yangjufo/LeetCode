class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stack;
        int maxCount = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stack.push(i);
            } else {
                if (!stack.empty() && s[stack.top()] == '(') {
                    stack.pop();
                    maxCount = max(maxCount, i - (stack.empty() ? -1 : stack.top()));
                } else {
                    stack.push(i);
                }
            }
        }
        return maxCount;
    }
};