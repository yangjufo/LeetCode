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