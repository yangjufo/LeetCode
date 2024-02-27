class Solution {
public:
    bool wordPatternMatch(string pattern, string s) {
        unordered_map<string, char> s2p;
        unordered_map<char, string> p2s;
        return backtrack(pattern, s, 0, 0, s2p, p2s);
    }

    bool backtrack(string& pattern, string& s, int pIndex, int sIndex,
                   unordered_map<string, char>& s2p,
                   unordered_map<char, string>& p2s) {
        if (pIndex >= pattern.length() && sIndex >= s.length()) {
            return true;
        }
        if (pIndex >= pattern.length() || sIndex >= s.length()) {
            return false;
        }
        char c = pattern[pIndex];
        if (p2s.find(c) != p2s.end()) {
            if (s.substr(sIndex, p2s[c].length()) != p2s[c]) {
                return false;
            }
            return backtrack(pattern, s, pIndex + 1, sIndex + p2s[c].length(),
                             s2p, p2s);
        }
        string curr;
        for (int i = sIndex; i < s.length(); i++) {
            curr += s[i];
            if (s2p.find(curr) != s2p.end()) {
                continue;
            }
            p2s[c] = curr;
            s2p[curr] = c;
            if (backtrack(pattern, s, pIndex + 1, i + 1, s2p, p2s)) {
                return true;
            }
            p2s.erase(c);
            s2p.erase(curr);
        }
        return false;
    }
};