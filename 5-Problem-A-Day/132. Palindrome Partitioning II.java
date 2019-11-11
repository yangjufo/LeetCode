class Solution {
    public int minCut(String s) {
        if (s == null || s.length() <= 1)
            return 0;

        int N = s.length();
        int[] dp = IntStream.range(0, N).toArray();

        for (int mid = 1; mid < N; mid++) {
            for (int start = mid, end = mid; start >= 0 && end < N
                    && s.charAt(start) == s.charAt(end); start--, end++) {
                int newCutAtEnd = (start == 0) ? 0 : dp[start - 1] + 1;
                dp[end] = Math.min(dp[end], newCutAtEnd);
            }
            for (int start = mid - 1, end = mid; start >= 0 && end < N
                    && s.charAt(start) == s.charAt(end); start--, end++) {
                int newCutAtEnd = (start == 0) ? 0 : dp[start - 1] + 1;
                dp[end] = Math.min(dp[end], newCutAtEnd);
            }
        }
        return dp[N - 1];
    }
}
