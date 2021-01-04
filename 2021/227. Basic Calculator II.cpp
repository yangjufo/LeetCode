class Solution {
public:
    int calculate(string s) {
        unordered_map<char, int> ranks = {
            {'+', 1},
            {'-', 1},
            {'*', 2},
            {'/', 2},
            {'#', 0}
        };
        stack<int> numStack;
        stack<char> opStack;
        int num = 0, i = 0;
        s += '#';
       for (int i = 0; i < s.length(); i++) {
            char c = s[i];            
            if (c >= '0' && c <= '9') {                
                num = num * 10 + (c - '0');                
            } else if (s[i] != ' ') {                
                numStack.push(num);                
                num = 0;
                while (!opStack.empty() && ranks[opStack.top()] >= ranks[c]) {
                    int second = numStack.top();
                    numStack.pop();
                    int first = numStack.top();
                    numStack.pop();
                    char op = opStack.top();
                    opStack.pop();

                    int tmp = (op == '*') ? first * second
                        : (op == '/') ? first / second
                            : (op == '+') ? first + second
                                : first - second;
                    numStack.push(tmp);
                }
                opStack.push(c);
            }       
        }                
        
        return numStack.top();
        
    }
};

class Solution {
public:
    int calculate(string s) {
        stack<int> numStack;
        char op = '+';
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            if ((!isdigit(c) && c != ' ') || i == s.length() - 1) {
                if (op == '+') {
                    numStack.push(num);
                } else if (op == '-') {
                    numStack.push(-num);
                } else if (op == '*') {
                    int lastNum = numStack.top();
                    numStack.pop();
                    numStack.push(lastNum * num);
                } else if (op == '/') {
                    int lastNum = numStack.top();
                    numStack.pop();
                    numStack.push(lastNum / num);
                }                
                op = c;
                num = 0;
            }
        }
        
        int ans = 0;
        while (!numStack.empty()) {
            ans += numStack.top();
            numStack.pop();
        }
        
        return ans;
    }
};

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
            if ((!isdigit(c) && c != ' ') || i == s.length() - 1) {
                if (op == '+' || op == '-') {
                    ans += lastNum;
                    lastNum = (op == '+') ? num : -num;
                } else if (op == '*') {
                    lastNum = lastNum * num;
                } else if (op == '/') {
                    lastNum = lastNum / num;
                }                
                op = c;
                num = 0;
            }
        }
        
        ans += lastNum;
        
        return ans;
    }
};

