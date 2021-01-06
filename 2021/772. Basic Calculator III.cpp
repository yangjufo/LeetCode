class Solution {
public:
    int calculate(string s) {
        stack<int> numStack;
        stack<char> opStack;
        long num = 0;
        s = "(" + s + ")";
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            } else if (s[i] == '+' || s[i] == '-') {
                while (!opStack.empty() && opStack.top() != '(') {
                    num = (opStack.top() == '+') ? numStack.top() + num 
                        : (opStack.top() == '-') ? numStack.top() - num
                            : (opStack.top() == '*') ? numStack.top() * num
                                : numStack.top() / num;
                    numStack.pop();
                    opStack.pop();                    
                }
                numStack.push(num);                    
                opStack.push(s[i]);    
                num = 0;
            } else if (s[i] == '*' || s[i] == '/') {
                while (!opStack.empty() && (opStack.top() == '*' || opStack.top() == '/')) {
                    num = (opStack.top() == '*') ? numStack.top() * num
                        : numStack.top() / num;
                    numStack.pop();
                    opStack.pop();
                }
                numStack.push(num);
                opStack.push(s[i]);
                num = 0;
            } else if (s[i] == '(') {
                opStack.push(s[i]);
            } else if (s[i] == ')') {
                while (opStack.top() != '(') {
                    int second = num;
                    int first = numStack.top();
                    num = (opStack.top() == '+') ? numStack.top() + num 
                        : (opStack.top() == '-') ? numStack.top() - num
                            : (opStack.top() == '*') ? numStack.top() * num
                                : numStack.top() / num;
                    numStack.pop();
                    opStack.pop();
                }
                opStack.pop();                
            }
        }
        return num;
    }
};

class Solution {
public:
    int calculate(string s) {
        unordered_map<char, int> ranks = 
        {
            {'(', 1},
            {'+', 2},
            {'-', 2},
            {'*', 3},
            {'/', 3}
        };
        
        stack<long> numStack;
        stack<char> opStack;
        for (int i = 0; i < s.length(); i++) {            
            if (isdigit(s[i])) {
                long num = s[i] - '0';
                while (i + 1 < s.length() && isdigit(s[i + 1])) {
                    i++;
                    num = num * 10 + (s[i] - '0');
                }
                numStack.push(num);
            } else if (s[i] == ' ') {
                continue;
            } else if (s[i] == '(') {
                opStack.push(s[i]);
            } else if (s[i] == ')') {
                while (opStack.top() != '(') {
                    numStack.push(operate(numStack, opStack));
                }
                opStack.pop();
            } else {
                while (!opStack.empty() && ranks[s[i]] <= ranks[opStack.top()]) {
                    numStack.push(operate(numStack, opStack));                   
                }
                 opStack.push(s[i]);
            }   
        }
        while (!opStack.empty()) {
            numStack.push(operate(numStack, opStack));            
        }
        return numStack.top();        
    }
    
    int operate(stack<long>& numStack, stack<char>& opStack) {
        long second = numStack.top();
        numStack.pop();        
        long first = 0;
        if (!numStack.empty()) {
            first = numStack.top();
            numStack.pop();
        }        
        char op = opStack.top();
        opStack.pop();
        
        switch(op) {
            case '*':
                return first * second;
            case '/':
                return first / second;
            case '+':
                return first + second;
            case '-':
                return first - second;
            default:
                return 0;
        }
    }
};

class Solution {
public:
    int calculate(string s) {
        unordered_map<char, int> ranks = 
        {
            {'(', 1},
            {'+', 2},
            {'-', 2},
            {'*', 3},
            {'/', 3}
        };
        
        stack<int> numStack;
        stack<char> opStack;
        long num = 0;
        for (int i = 0; i < s.length(); i++) {
            // if (s[i] == ' ') continue;
            // if (!numStack.empty()) {
            //     cout << "numStack top: " << numStack.top() << ", ";
            // }
            // if (!opStack.empty()) {
            //     cout << "opStack top: " << opStack.top() << ", ";
            // }
            // cout << "num: " << num << ", ";
            // cout << "s[i]: " << s[i] << endl;
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            } else if (s[i] == '(') {
                opStack.push(s[i]);
            } else if (s[i] == ')') {
                while (opStack.top() != '(') {
                    int second = num;
                    int first = numStack.top();
                    num = (opStack.top() == '+') ? numStack.top() + num 
                        : (opStack.top() == '-') ? numStack.top() - num
                            : (opStack.top() == '*') ? numStack.top() * num
                                : numStack.top() / num;
                    numStack.pop();
                    opStack.pop();
                }
                opStack.pop();                
            } else if (s[i] != ' ') {
                while (!opStack.empty() && ranks[s[i]] <= ranks[opStack.top()]) {
                    num = (opStack.top() == '+') ? numStack.top() + num 
                        : (opStack.top() == '-') ? numStack.top() - num
                            : (opStack.top() == '*') ? numStack.top() * num
                                : numStack.top() / num;
                    numStack.pop();
                    opStack.pop();                    
                }
                numStack.push(num);                    
                opStack.push(s[i]);    
                num = 0;
            }
        }
        
         while (!opStack.empty()) {
                num = (opStack.top() == '+') ? numStack.top() + num 
                    : (opStack.top() == '-') ? numStack.top() - num
                        : (opStack.top() == '*') ? numStack.top() * num
                            : numStack.top() / num;
                numStack.pop();
                opStack.pop();                    
        }
        return num;
    }
};