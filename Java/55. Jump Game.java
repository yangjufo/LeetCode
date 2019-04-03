class Solution {
    public boolean canJump(int[] nums) {
        int max = 0;
        while (max < nums.length - 1) {
            int tmp = max;
            for (int i = 0; i < tmp + 1; i++) {
                max = Math.max(nums[i] + i, max);
            }
            if (tmp == max && max < nums.length)
                return false;
        }
        return true;
    }
}