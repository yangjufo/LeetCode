class Solution {
    public int minCost(int[][] costs) {
        int m = costs.length;
        if (m == 0)
            return 0;
        int[][] dp = new int[m + 1][3];
        for (int i = 1; i < m + 1; i++) {
            dp[i][0] = Math.min(dp[i - 1][1], dp[i - 1][2]) + costs[i - 1][0];
            dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][2]) + costs[i - 1][1];
            dp[i][2] = Math.min(dp[i - 1][0], dp[i - 1][1]) + costs[i - 1][2];
        }
        return Math.min(dp[m][0], Math.min(dp[m][1], dp[m][2]));
    }
}
