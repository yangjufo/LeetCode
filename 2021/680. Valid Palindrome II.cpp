class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }
        return true;
    }
    
    bool isPalindrome(string& s, int left, int right) {
        while (left < right && s[left] == s[right]) {
            left++;
            right--;
        }        
        return left >= right;
    }
};