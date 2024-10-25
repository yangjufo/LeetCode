class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> stack;
        for (int c : s) {
            if (stack.empty() || c != stack.back()) {
                stack.push_back(c);
            } else {
                stack.pop_back();
            }
        }
        string res;
        for (char c : stack) {
            res += c;
        }
        return res;
    }
};

class Solution {
public:
    string removeDuplicates(string s) {
        int i = 0;
        for (int j = 0; j < s.length(); j++, i++) {
            s[i] = s[j];
            if (i > 0 && s[i - 1] == s[i]) {
                i -= 2;
            }
        }
        return s.substr(0, i);
    }
};