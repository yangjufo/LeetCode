class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> c2s;
        unordered_map<string, char> s2c;
        int start = -1;
        for (char c : pattern) {
            int next = s.find(" ", start + 1);
            string word = s.substr(start + 1, next - start - 1);            
            if ((c2s.find(c) != c2s.end() && c2s[c] != word) || (s2c.find(word) != s2c.end() && s2c[word] != c)) {
                return false;
            }
            c2s[c] = word;
            s2c[word] = c;
            start = next;
        }
        return start >= s.length();
    }
};

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> pMap;
        unordered_map<string, int> sMap;
        int start = 0, i = 0;
        for (; i < pattern.length() && start < (int)s.length(); i++) {                             
            int next = min(s.find(" ", start), s.length());
            string word = s.substr(start, next - start);
            if (pMap[pattern[i]] != sMap[word]) {
                return false;
            }
            pMap[pattern[i]] = i + 1;
            sMap[word] = i + 1;
            start = next + 1;
        }                
        return i >= pattern.length() && start >= s.length();
    }
};