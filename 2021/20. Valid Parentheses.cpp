class Solution {
public:
    bool isValid(string s) {
        stack<char> sStack;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                sStack.push(c);
            } else {
                if (sStack.empty() 
                    || (c == ')' && sStack.top() != '(')
                    || (c == '}' && sStack.top() != '{')
                    || (c == ']' && sStack.top() != '[')) {
                    return false;
                }
                sStack.pop();
            }
        }
        return sStack.empty();
    }
};

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else {
                if (stack.empty()) return false;
                if (c == ')') {
                    if (stack.top() != '(') {
                        return false;
                    }
                } else if (c == '}') {
                    if (stack.top() != '{') {
                        return false;
                    }
                } else if (c == ']') {
                    if (stack.top() != '[') {
                        return false;
                    }
                }
                stack.pop();
            }            
        }
        return stack.empty();
    }
};