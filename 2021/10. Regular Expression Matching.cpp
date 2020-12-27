class Solution {
public:
    bool isMatch(string s, string p) {                
        return isMatch(s, 0, p, 0);
    }
    
    bool isMatch(string& s, int sStart, string& p, int pStart) {        
        if (pStart >= p.length()) return sStart >= s.length();
        bool firstMatch = (sStart < s.length() && (s[sStart] == p[pStart] || p[pStart] == '.'));
        if (pStart < p.length() - 1 && p[pStart + 1] == '*') {
            return isMatch(s, sStart, p, pStart + 2)
                || (firstMatch && isMatch(s, sStart + 1, p, pStart));
        }
        return firstMatch && isMatch(s, sStart + 1, p, pStart + 1);
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[s.length() + 1][p.length() + 1];
        dp[s.length()][p.length()] = true;
        for (int i = 0; i < s.length(); i++) {
            dp[i][p.length()] = false;
        }
        for (int i = s.length(); i >= 0; i--) {
            for (int j = p.length() - 1; j >= 0; j--) {
                bool firstMatch = i < s.length() && (s[i] == p[j] || p[j] == '.');
                if (j < p.length() - 1 && p[j + 1] == '*') {
                    dp[i][j] = dp[i][j + 2] || firstMatch && dp[i + 1][j];
                } else {                    
                    dp[i][j] = firstMatch && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};