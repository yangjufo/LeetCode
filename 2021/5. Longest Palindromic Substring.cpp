class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0, maxStart = 0;
        for (int i = 0; i < s.length() && maxLen < s.length(); i++) {
            int one = extend(s, i, i);
            int two = extend(s, i, i + 1);
            if (one > maxLen) {
                maxLen = one;
                maxStart = i - one / 2;
            }
            if (two > maxLen) {
                maxLen = two;
                maxStart = i - two / 2 + 1;
            }
        }
        
        return s.substr(maxStart, maxLen);
    }
    
    int extend(string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {        
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        int maxLen = 0, maxStart = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = (i + 1 <= j - 1) ? dp[i+1][j-1] : true;
                    if (dp[i][j] && j - i + 1 > maxLen) {
                        maxStart = i;
                        maxLen = j - i + 1;
                    }
                } else {
                    dp[i][j] = false;
                }
            }
        }                    
        return s.substr(maxStart, maxLen);
    }        
};


class Solution {
public:
    string longestPalindrome(string s) {        
        int maxLen = 0, maxStart = 0;
        for (int i = 0; i < s.length(); i++) {
            int left = expand(s, i, i);
            if ((i - left) * 2 + 1 > maxLen) {
                maxStart = left;
                maxLen = (i - left) * 2 + 1;
            } 
            left = expand(s, i, i + 1);
            if ((i - left + 1) * 2 > maxLen) {
                maxStart = left;
                maxLen = (i - left + 1) * 2;
            }
        }
        return s.substr(maxStart, maxLen);
    }
    
    int expand(string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        left++;
        right--;
        return left;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        int maxStart = 0, maxLen = 0;
        for (int i = (int)s.length() - 1; i >= 0; i--) {
            for (int j = i; j < (int)s.length(); j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = (i + 1 < j - 1) ? dp[i + 1][j - 1] : true;
                }                
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxStart = i;
                    maxLen = j - i + 1;
                }
            }            
        }
        return s.substr(maxStart, maxLen);
    }
};