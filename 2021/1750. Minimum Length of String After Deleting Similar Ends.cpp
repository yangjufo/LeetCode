class Solution {
public:
    int minimumLength(string s) {
        int left = 0, right = s.length() - 1, minLen = s.length();
        while (left < right && s[left] == s[right]) {            
            char c = s[left];
            while (left <= right && s[left] == c) {
                left++;
            }
            while (left <= right && s[right] == c) {
                right--;
            }
            
            minLen = min(minLen, right - left + 1);
        }
        return minLen < 0 ? 0 : minLen;
    }
};