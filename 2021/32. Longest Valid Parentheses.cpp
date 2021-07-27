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

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char, int>> pStack;        
        int maxLen = 0;
        for (char c : s) {
            if (c == '(') {
                pStack.push({'(', 2});
            } else {
                int curr = 0;
                while (!pStack.empty() && pStack.top().first != '(') {
                    curr += pStack.top().second;
                    pStack.pop();
                }
                maxLen = max(maxLen, curr);
                if (!pStack.empty() && pStack.top().first == '(') {
                    curr += 2;
                    pStack.pop();
                    maxLen = max(maxLen, curr);
                    pStack.push({'n', curr});
                }                
            }
        }
        int curr = 0;
        while (!pStack.empty()) {
            if (pStack.top().first == 'n') {
                curr += pStack.top().second;
            } else {
                curr = 0;
            }            
            pStack.pop();
            maxLen = max(maxLen, curr);
        }                            
        return maxLen;
    }
};


class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        stack<int> index;
        index.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                index.push(i);
            } else {
                index.pop();
                if (index.empty()) {
                    index.push(i);
                } else {                    
                    maxLen = max(maxLen, i - index.top());
                }
            }
        }
        return maxLen;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stack;
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stack.push(-1);
            } else {
                int currLen = 0;
                while (!stack.empty() && stack.top() != -1) {
                    currLen += stack.top();    
                    stack.pop();
                }
                if (!stack.empty()) {
                    stack.pop();
                    currLen += 2;
                    stack.push(currLen);
                }
                maxLen = max(maxLen, currLen);
            }
        }
        int currLen = 0;
        while (!stack.empty()) {
            if (stack.top() != -1) {
                currLen += stack.top();
            } else {
                currLen = 0;                
            }
            maxLen = max(maxLen, currLen);
            stack.pop();
        }
        return maxLen;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        stack<int> index;
        index.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                index.push(i);
            } else {
                index.pop();
                if (index.empty()) {                
                    index.push(i);
                } else {
                    maxLen = max(maxLen, i - index.top());
                }                
            }
        }
        return maxLen;
    }
};