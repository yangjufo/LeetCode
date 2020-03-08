class Solution {
    public int maxProduct(int[] nums) {
        int ans = nums[0];
        for (int i = 1, max = nums[0], min = nums[0]; i < nums.length; i++){
            if (nums[i] < 0) {
                int tmp = max;
                max = min;
                min = tmp;
            }      
            
            max = Math.max(nums[i], nums[i] * max);
            min = Math.min(nums[i], nums[i] * min);
            ans = Math.max(ans, max);
        }
        return ans;
    }
}