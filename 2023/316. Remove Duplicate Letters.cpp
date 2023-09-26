class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ret;
        vector<int> count(26, 0);
        vector<bool> visited(26, false);
        for (char c : s) {
            count[c - 'a']++;
        }
        for (char c : s) {
            count[c - 'a']--;
            if (visited[c - 'a']) {
                continue;
            }
            while (!ret.empty() && ret.back() > c && count[ret.back() - 'a'] > 0) {
                visited[ret.back() - 'a'] = false;
                ret.pop_back();
            }
            ret += c;
            visited[c - 'a'] = true;
        }
        return ret;
    }
};