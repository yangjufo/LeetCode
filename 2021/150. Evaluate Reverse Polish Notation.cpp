class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numStack;
        for (string t : tokens) {
            if (t.length() == 1 && !isdigit(t[0])) {              
                int num2 = numStack.top();
                numStack.pop();
                int num1 = numStack.top();
                numStack.pop();
                int ans;
                switch(t[0]) {
                    case '+':
                        ans = num1 + num2;
                        break;
                    case '-':
                        ans = num1- num2;
                        break;
                    case '*':
                        ans = num1 * num2;
                        break;
                    case '/':
                        ans = num1 / num2;
                        break;
                    default:
                        break;
                }
                numStack.push(ans);
            } else {
                numStack.push(stoi(t));
            }
        }
        return numStack.top();
    }
};