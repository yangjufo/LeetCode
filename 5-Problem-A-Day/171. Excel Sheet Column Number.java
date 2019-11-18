class Solution {
    public int titleToNumber(String s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            ans = ans * 26 + (int) c - 64;
        }
        return ans;
    }
}
