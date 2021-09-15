class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0, right = (int)s.length() - 1;
        while (left < right) {
            while (left < right && !((s[left] >= 'a' && s[left] <= 'z') || (s[left] >= 'A' && s[left] <= 'Z'))) {
                left++;
            }
            while (left < right && !((s[right] >= 'a' && s[right] <= 'z') || (s[right] >= 'A' && s[right] <= 'Z'))) {
                right--;
            }            
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};