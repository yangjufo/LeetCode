class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> strStack;
        int count = 0;
        string str;
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                count = count * 10 + (s[i] - '0');                
            } else if (s[i] == '[') {
                countStack.push(count);                
                strStack.push(str);
                str = "";
                count = 0;
            } else if (s[i] == ']') {                
                string tmp = strStack.top();
                strStack.pop();
                tmp = tmp + repeat(str, countStack.top());
                countStack.pop();
                str = tmp;
            } else {
                str += s[i];
            }
        }
        return str;
    }
    
    string repeat(string s, int n) {
        string ans;
        for (int i = 0; i < n; i++) {
            ans += s;
        }
        return ans;
    }
};