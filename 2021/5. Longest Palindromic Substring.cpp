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