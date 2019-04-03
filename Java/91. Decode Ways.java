class Solution {
    public int numDecodings(String s) {
        int[] dp = new int[s.length() + 1];
        Arrays.fill(dp, 0);
        dp[0] = 1;
        for (int i = 1; i < s.length() + 1; i++) {
            if (s.charAt(i - 1) >= '1' && s.charAt(i - 1) <= '9')
                dp[i] += dp[i - 1];
            if (i != 1) {
                if (s.charAt(i - 1) >= '0' && s.charAt(i - 1) <= '9' && s.charAt(i - 2) == '1')
                    dp[i] += dp[i - 2];
                if (s.charAt(i - 1) >= '0' && s.charAt(i - 1) <= '6' && s.charAt(i - 2) == '2')
                    dp[i] += dp[i - 2];
            }
            if (s.charAt(i - 1) == '0' && (i == 1 || (s.charAt(i - 2) != '1' && s.charAt(i - 2) != '2')))
                return 0;            
        }
        return dp[s.length()];
    }
}