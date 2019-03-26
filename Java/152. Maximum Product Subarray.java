class Solution {
    public int maxProduct(int[] nums) {
        int min, max, res;
        max = min = res = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < 0) {
                int tmp = min;
                min = max;
                max = tmp;                
            }                        
            max = Math.max(nums[i], nums[i] * max);
            min = Math.min(nums[i], nums[i] * min);            
            if (max > res) res = max;                        
        }
        return res;
    }
}