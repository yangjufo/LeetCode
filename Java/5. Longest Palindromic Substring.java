class Solution {
    
    private Integer maxLen = 0;
    private Integer maxLeft = 0, maxRight = 0;
    
    private void isPalindrome(Integer left, Integer right, String s) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                maxLeft = left;
                maxRight = right;
            }
            left -= 1;
            right += 1;
        }        
    }
    
    public String longestPalindrome(String s) {        
        if (s.length() == 0) return "";
        for (int i = 0; i < s.length(); i++) {
            isPalindrome(i, i, s);
            if (i < s.length() - 1 && s.charAt(i) == s.charAt(i + 1))
                isPalindrome(i, i + 1, s);            
        }
        return s.substring(maxLeft, maxRight + 1);
    }
}