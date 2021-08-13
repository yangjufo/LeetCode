class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        if (s.empty()) return s;
        string res;
        int count = 0;
        for (int i = (int)s.length() - 1; i >= 0; i--) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                res += s[i] + 'A' - 'a';
                count++;
            } else if (s[i] != '-') {
                res += s[i];
                count++;
            }
            if (count % k == 0 && i != 0 && s[i] != '-') {
                res += '-';
            }
        }        
        reverse(res.begin(), res.end());
        return res[0] == '-' ? res.substr(1) : res;
    }
};

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {        
        string res;        
        for (int i = (int)s.length() - 1; i >= 0; i--) {
            if (s[i] == '-') {
                continue;
            }                        
            if (res.size() % (k + 1) == k) {
                res += '-';
            }
            res += toupper(s[i]);        
        }        
        reverse(res.begin(), res.end());
        return res;
    }
};