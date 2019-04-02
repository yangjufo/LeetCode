class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        int[] dp = new int[s.length() + 1];
        dp[0] = 1;
        Set<String> wordSet = new HashSet<String>(wordDict);
        for (int i = 1; i < s.length() + 1; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] == 1 && wordSet.contains(s.substring(j, i)))
                    dp[i] = 1;
            }            
        }
        return dp[s.length()] == 1;
    }
}