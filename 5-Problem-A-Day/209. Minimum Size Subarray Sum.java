class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int len = nums.length + 1, start = 0, sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            while (sum >= s) {
                len = Math.min(len, i - start + 1);
                sum -= nums[start];
                start++;
            }
        }
        return len == nums.length + 1 ? 0 : len;
    }
}
