class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> cs;
        for (char c : s) {
            if (!cs.empty() && c == cs.top()) {
                cs.pop();
            } else {
                cs.push(c);
            }
        }
        string res;
        while (!cs.empty()) {
            res += cs.top();
            cs.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};