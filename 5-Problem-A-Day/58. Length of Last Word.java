class Solution {
    public int lengthOfLastWord(String s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i != 0 && s.charAt(i) != ' ' && s.charAt(i - 1) == ' ')
                ans = 1;
            else if (s.charAt(i) != ' ')
                ans += 1;
        }
        return ans;
    }
}
