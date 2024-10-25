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