class Solution {
public:
    int countSubstrings(string s) {
        int total = 0;
        for (int i = 0; i < s.length(); i++) {
            total += extend(s, i, i);
            total += extend(s, i, i + 1);
        }
        return total;
    }
    
    int extend(string&s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = i; j < s.length(); j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = (i + 1 < j - 1) ? dp[i + 1][j - 1] : true;                   
                    count += dp[i][j] ? 1 : 0;
                }                
            }
        }
        return count;
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length(), count = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = i; j < s.length(); j++) {
                if (s[i] == s[j]) {
                    if (i + 1 < j - 1) {
                        dp[i][j] = dp[i + 1][j - 1];                        
                    } else {
                        dp[i][j] = true;
                    }
                    count += dp[i][j] ? 1 : 0;
                }
            }
        }
        return count;
    }
};