class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (string& w : words) {
            unordered_map<char, char> wp, pw;
            if (w.length() != pattern.length()) {
                continue;
            }
            bool match = true;
            for (int i = 0; i < w.length(); i++) {
                if ((wp.find(w[i]) != wp.end() && wp[w[i]] != pattern[i]) || (pw.find(pattern[i]) != pw.end() && pw[pattern[i]] != w[i])) {
                    match = false;
                    break;
                }
                wp[w[i]] = pattern[i];
                pw[pattern[i]] = w[i];
            }
            if (match) {
                res.push_back(w);
            }
        }
        return res;
    }
};