class Solution {
public:
    string parseTernary(string expression) {
        stack<char> eStack;
        for (int i = (int)expression.length() - 1; i >= 0; i--) {
            if (expression[i] != '?' && expression[i] != ':') {
                eStack.push(expression[i]);
            }
            if (i + 1 < (int) expression.length() && expression[i + 1] == '?') {
                char flag = eStack.top();
                eStack.pop();
                char left = eStack.top();
                eStack.pop();
                char right = eStack.top();
                eStack.pop();                                
                char res = flag == 'T' ? left : right;
                eStack.push(res);
            }
        }
        string ret;
        ret += eStack.top();
        return ret;
    }
};