class Solution {
    int[][] memo;
    
    public boolean isMatch(String s, String p) {
        memo = new int[s.length() + 1][p.length() + 1];        
        return check(0, 0, s, p);
    }
    
    private boolean check(int i, int j, String s, String p) {
        if (memo[i][j] != 0)
            return memo[i][j] == 1;
        boolean ans;
        if (j == p.length())
            ans = i == s.length();
        else {
            boolean first_match = (i < s.length() && (p.charAt(j) == s.charAt(i) || p.charAt(j) == '.'));
            if (j + 1 < p.length() && p.charAt(j + 1) == '*')
                ans = (check(i, j + 2, s, p)) || first_match && check(i + 1, j, s, p);
            else
                ans = first_match && check(i + 1, j + 1, s, p);
        }
        memo[i][j] = ans ? 1 : -1;
        return ans;
    }
}