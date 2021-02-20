class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> pStack;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                pStack.push(i);
            } else if (s[i] == ')') {
                if (!pStack.empty()) {                    
                    pStack.pop();                    
                } else {
                    s[i] = '#';
                }                
            }
        }
        while (!pStack.empty()) {
            s[pStack.top()] = '#';
            pStack.pop();
        }
        string ans;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '#') {
                ans += s[i];
            }
        }
        return ans;
    }
};

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0, close = 0;
        string first;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                open++;
            } else if (s[i] == ')') {
                if (close == open) {
                    continue;
                }
                close++;                
            }
            first += s[i];
        }
        
        string ans;
        int openKeep = close;
        for (int i = 0; i < first.length(); i++) {
            if (first[i] == '(') {
                openKeep--;
                if (openKeep < 0) continue;
            }            
            ans += first[i];
        }
        return ans;
    }
};


class Solution {
public:
    string minRemoveToMakeValid(string s) {        
        int openCount = 0, closeCount = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                openCount++;
            }
            if (s[i] == ')' && openCount > closeCount) {
                closeCount++;
            }
        }
        
        int openKeep = min(openCount, closeCount);
        openCount = 0, closeCount = 0;
        string str;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                if (openCount < openKeep) {                    
                    str += s[i];
                    openCount++;
                }
            } else if (s[i] == ')') {
                if (openCount > closeCount) {
                    str += s[i];
                    closeCount++;
                }
            } else {
                str += s[i];
            }
        }
        return str;
    }
};


class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> pStack;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                pStack.push(i);
            } else if (s[i] == ')') {
                if (pStack.empty()) {
                    s[i] = '#';
                } else {
                    pStack.pop();
                }
            }
        }
        while (!pStack.empty()) {
            s[pStack.top()] = '#';
            pStack.pop();
        }
        string res;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '#') {
                res += s[i];
            }               
        }
        return res;
    }
};