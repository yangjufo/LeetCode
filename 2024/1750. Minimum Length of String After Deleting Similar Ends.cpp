class Solution {
public:
    int minimumLength(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right && s[left] == s[right]) {
            while (left < right && s[left + 1] == s[left]) {
                left++;
            }
            while (left < right && s[right - 1] == s[right]) {
                right--;
            }
            left++;
            right--;
        }
        return max(0, right - left + 1);
    }
};