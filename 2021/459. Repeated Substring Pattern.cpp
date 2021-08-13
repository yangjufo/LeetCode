class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int i = 1; i * 2 - 1 < s.length(); i++) {
            if (s[i] == s[0] && repeat(s, i)) {
                return true;
            }
        }    
        return false;
    }
    
    bool repeat(string& s, int repeatStart) {
        int i = 0, j = repeatStart;
        while (j < s.length() && s[j] == s[i]) {
            j++;
            i = (i + 1) % repeatStart;
        }
        return j >= s.length() && i == 0;
    }
};

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int i = 1; i * 2 - 1 < s.length(); i++) {
            if (s[i] == s[0] && repeat(s, i)) {
                return true;
            }
        }    
        return false;
    }
    
    bool repeat(string& s, int len) {
        string target = s.substr(0, len);
        int j = len;
        while (j + len <= s.length() && s.substr(j, len) == target) {
            j += len;            
        }
        return j >= s.length();
    }
};

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        return t.substr(1, (int)t.length() - 2).find(s) != string::npos;
    }
};