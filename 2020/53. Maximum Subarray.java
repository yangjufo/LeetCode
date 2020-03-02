class Solution {
    public int maxSubArray(int[] nums) {
        int sum = 0, ans = Integer.MIN_VALUE;
        for (int n : nums) {
            sum += n;
            ans = Math.max(sum, ans);
            sum = Math.max(0, sum);
        }
        return ans;
    }
}
