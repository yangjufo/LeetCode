class Solution {
public:
    string repeat(string s, int n) {
        string res;
        for (int i = 0; i < n; i++) {
            res += s;
        }
        return res;
    }
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> strStack;
        int count = 0;
        string str;
        for (char c : s) {
            if (isdigit(c)) {
                count = count * 10 + c - '0';
            } else if (c == '[') {
                countStack.push(count);
                strStack.push(str);
                count = 0;
                str.clear();
            } else if (c == ']') {
                string tmp = strStack.top();
                strStack.pop();
                tmp = tmp + repeat(str, countStack.top());
                countStack.pop();
                str = tmp;
            } else {
                str += c;
            }
        }
        return str;
    }
};