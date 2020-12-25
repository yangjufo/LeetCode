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