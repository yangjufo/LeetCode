class Solution {
public:
    unordered_map<char, char> pairs = {
        {']', '['},
        {')', '('},
        {'}', '{'}
    };
    bool isValid(string s) {
        stack<char> stack;
        for (char c : s) {
            if (pairs.find(c) != pairs.end()) {
                if (stack.empty() || stack.top() != pairs[c]) {
                    return false;
                }
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};