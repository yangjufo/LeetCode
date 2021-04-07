class Solution {
public:
    bool isIsomorphic(string s, string t) {        
        unordered_map<char, char> s2t, t2s;        
        for (int i = 0; i < s.length(); i++) {
            if (s2t.find(s[i]) == s2t.end()) {
                if (t2s.find(t[i]) != t2s.end()) {
                    return false;
                }
                s2t[s[i]] = t[i];
                t2s[t[i]] = s[i];
            } else if (s2t[s[i]] != t[i] || t2s.find(t[i]) == t2s.end() || t2s[t[i]] != s[i]) {
                    return false;            
            }            
        }
        return true;
    }
};

class Solution {
public:
    bool isIsomorphic(string s, string t) {        
        int m1[256], m2[256];
        for (int i = 0; i < 256; i++) {
            m1[i] = m2[i] = -1;
        }
        for (int i = 0; i < s.length(); i++) {            
            if (m1[s[i]] != m2[t[i]]) return false;            
            m1[s[i]] = i;
            m2[t[i]] = i;
        }
        return true;
    }
};