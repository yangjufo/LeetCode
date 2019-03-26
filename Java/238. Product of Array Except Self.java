class Solution {
    public int[] productExceptSelf(int[] nums) {
        int left = 1;
        int[] res = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {            
            res[i] = left;
            left *= nums[i];
        }
        left = 1;
        for (int i = nums.length - 1; i > -1; i--) {
            res[i] *= left;
            left *= nums[i];
        }
        return res;
    }
}