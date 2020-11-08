class Solution {
    public int getMaximumGenerated(int n) {
        int[] nums = new int[101];
        nums[0] = 0;
        nums[1] = 1;
        int max = (n == 0) ? 0 : 1;
        for (int i = 2; i <= n; i++) {
            if (i % 2 == 0) {
                nums[i] = nums[i / 2];
            } else {
                nums[i] = nums[i / 2] + nums[i / 2 + 1];
            }
            max = (nums[i] > max) ? nums[i] : max;
        }
        return max;
    }
}