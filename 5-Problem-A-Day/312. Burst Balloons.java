class Solution {
    public int maxCoins(int[] nums) {
        int n = nums.length + 2;
        int[] newNums = new int[n];

        for (int i = 0; i < nums.length; i++)
            newNums[i + 1] = nums[i];

        newNums[0] = newNums[n - 1] = 1;

        int[][] memo = new int[n][n];

        return dp(memo, newNums, 0, n - 1);
    }

    private int dp(int[][] memo, int[] nums, int left, int right) {
        if (left + 1 == right)
            return 0;

        if (memo[left][right] > 0)
            return memo[left][right];

        int ans = 0;
        for (int i = left + 1; i < right; i++)
            ans = Math.max(ans, nums[left] * nums[i] * nums[right] + dp(memo, nums, left, i)
                    + dp(memo, nums, i, right));

        memo[left][right] = ans;
        return ans;
    }
}
