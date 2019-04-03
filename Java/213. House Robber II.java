class Solution {
    public int rob(int[] nums) {        
        int pre = 0, curr = 0, max = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            int tmp = curr;
            curr = Math.max(pre + nums[i], curr);
            pre = tmp;
        }
        max = curr;        
        pre = curr = 0;
        for (int i = 1; i < nums.length; i++) {
            int tmp = curr;
            curr = Math.max(pre + nums[i], curr);
            pre = tmp;
        }
        max = Math.max(max, curr);
        if (nums.length > 0)            
            return Math.max(max, nums[0]);
        else
            return max;
    }
}