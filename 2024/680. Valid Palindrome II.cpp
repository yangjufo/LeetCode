class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while (left <= right) {
            if (s[left] != s[right]) {
                return valid(s, left + 1, right) || valid(s, left, right - 1);
            }
            left += 1;
            right -= 1;
        }
        return true;
    }

    bool valid(string& s, int left, int right) {
        while (left <= right) {
            if (s[left] != s[right]) {
                return false;
            }
            left += 1;
            right -= 1;
        }
        return true;
    }
};