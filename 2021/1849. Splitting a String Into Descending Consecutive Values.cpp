class Solution {
public:
    long max_int = 9999999999;
    bool splitString(string s) {
        long num = 0;
        for (int i = 0; i < s.length() - 1; i++) {            
            num = num * 10 + (s[i] - '0');
            if (num > max_int) break;
            
            if(backtrack(s, num, i + 1)) {
                return true;
            }
        }
        return false;
    }
    
    bool backtrack(string& s, long last, int start) {
        if (start >= s.length()) return true;
        long num = 0;
        for (int i = start; i < s.length(); i++) {            
            num = num * 10 + (s[i] - '0');
            if (num > max_int) break;
            
            if (num == last - 1 && backtrack(s, num, i + 1)) {
                return true;
            }
        }
        return false;
    }
    
};