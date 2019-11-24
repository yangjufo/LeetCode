class Solution {
    public String shortestPalindrome(String s) {
        int n = s.length();
        String res = new StringBuilder(s).reverse().toString();
        for (int i = 0; i < n; i++) {
            if (s.substring(0, n - i).equals(res.substring(i)))
                return res.substring(0, i) + s;
        }
        return "";
    }
}
