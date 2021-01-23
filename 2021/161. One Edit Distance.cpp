class Solution {
public:
    bool isOneEditDistance(string s, string t) {        
        if (s.length() > t.length() + 1 || t.length() > s.length() + 1) return false;
        if (t.length() + s.length() == 1) return true;
        int i = 0, j = 0;
        bool diff = false;
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++;
                j++;
            }
            else 
            {
                if (diff) return false;
                if (t.length() > s.length()) {
                    j++;
                } else if (t.length() < s.length()) {
                    i++;
                } else {
                    i++;
                    j++;
                }         
                diff = true;
            }            
        }
        return diff || (t.length() != s.length());
    }
};

class Solution {
public:
    bool isOneEditDistance(string& s, string& t) {        
        if (s.length() > t.length()) return isOneEditDistance(t, s);
        int lenDiff = t.length() - s.length();
        if (lenDiff > 1) return false;
        int i = 0;        
        while (i < s.length()) {
            if (s[i] != t[i]) {
                return lenDiff == 0 ? s.substr(i + 1) == t.substr(i + 1)
                    : s.substr(i) == t.substr(i + 1);
            }
            i++;
        }
        return lenDiff == 1;
    }
};