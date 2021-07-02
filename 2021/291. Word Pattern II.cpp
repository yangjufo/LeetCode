class Solution {
public:
    bool wordPatternMatch(string pattern, string s) {
        unordered_map<string, char> s2c;
        unordered_map<char, string> c2s;
        return backtrack(pattern, 0, s, 0, s2c, c2s);
    }
    
    bool backtrack(string& pattern, int pIndex, string& s, int sIndex, unordered_map<string, char>& s2c, unordered_map<char, string>& c2s) {
        if (pIndex >= pattern.length() && sIndex >= s.length()) return true;
        if (pIndex >= pattern.length() || sIndex >= s.length()) return false;
        char c = pattern[pIndex];
        if (c2s.find(c) != c2s.end()) {
            if (s.substr(sIndex, c2s[c].length()) != c2s[c]) {                
                return false;
            }
            sIndex += c2s[c].length();
            return backtrack(pattern, pIndex + 1, s, sIndex, s2c, c2s);
        } else {
            string curr;
            for (int i = sIndex; i < s.length(); i++) {
                curr += s[i];
                if (s2c.find(curr) != s2c.end()) {
                    continue;
                }
                c2s[c] = curr;
                s2c[curr] = c;
                if (backtrack(pattern, pIndex + 1, s, i + 1, s2c, c2s)) {
                    return true;
                }
                c2s.erase(c);
                s2c.erase(curr);
            }
        }
        return false;
    }
};