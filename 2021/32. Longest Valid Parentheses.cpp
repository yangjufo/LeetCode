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


class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> pStack;
        int maxLen = 0;
        for (char c : s) {
            if (c == '(') {
                pStack.push(-1);
            } else {
                int curr = 0;
                while (!pStack.empty() && pStack.top() > 0) {
                    curr += pStack.top();
                    pStack.pop();
                }
                if (!pStack.empty() && pStack.top() == -1) {
                    pStack.pop();
                    curr += 2;
                    while (!pStack.empty() && pStack.top() > 0) {
                        curr += pStack.top();
                        pStack.pop();
                    }
                } else {
                    curr = 0;
                    while (!pStack.empty()) {
                        pStack.pop();
                    }
                }         
                if (curr > 0) {
                    pStack.push(curr);
                }
                maxLen = max(maxLen, curr);
            }
        }
        return maxLen;
    }
};