class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        stack<int> pStack;
        pStack.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                pStack.push(i);
            } else {
                pStack.pop();
                if (pStack.empty()) {
                    pStack.push(i);
                } else {
                    maxLen = max(maxLen, i - pStack.top());
                }
            }
        }
        return maxLen;
    }
};


class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0, close = 0, maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                open++;
            } else {
                close++;
            }
            
            if (open == close) {
                maxLen = max(maxLen, close * 2);
            } 
            if (close > open) {
                open = close = 0;
            }
        }
        
        open = close = 0;
        for (int i = s.length(); i >= 0; i--) {
            if (s[i] == ')') {
                open++;
            } else {
                close++;
            }
            if (open == close) {
                maxLen = max(maxLen, close * 2);
            }
            if (close > open) {
                open = close = 0;
            }
        }
        
        return maxLen;
    }
};