class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0);
        vector<bool> visited(26, false);
        for (char c : s) {
            count[c - 'a']++;
        }
        stack<char> cStack;
        for (char c : s) {
            count[c - 'a']--;
            if (visited[c - 'a']) {
                continue;
            }
            while (!cStack.empty() && cStack.top() > c && count[cStack.top() - 'a'] > 0) {
                visited[cStack.top() - 'a'] = false;
                cStack.pop();
            }
            cStack.push(c);
            visited[c - 'a'] = true;
        }
        string res;
        while (!cStack.empty()) {
            res += cStack.top();
            cStack.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};