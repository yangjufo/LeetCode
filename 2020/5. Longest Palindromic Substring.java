class Solution {
    public String longestPalindrome(String s) {
        int start = 0, end = 0, max = 0;
        for (int i = 0; i < s.length(); i++) {
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i + 1);
            if (len1 > max) {
                max = len1;
                start = i - len1 / 2;
                end = i + len1 / 2;
            } 
            if (len2 > max) {
                max = len2;
                start = i - (len2 - 1) / 2;
                end = i + len2 / 2;
            }
        }
        return s.substring(start, end + 1);
    }
    
    private int expand(String s, int left, int right) {
        while (left > -1 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;            
        }
        return right - left - 1;
    }
}