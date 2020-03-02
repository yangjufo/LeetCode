class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] ans = new int[nums.length];
        int left = 1, right = 1;
        for (int i = 0; i < nums.length; i++) {
            ans[i] = left;
            left *= nums[i];
        }
        for (int i = nums.length - 1; i > -1; i--) {
            ans[i] *= right;
            right *= nums[i];
        }
        return ans;
    }
}
