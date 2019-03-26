class Solution {
    public int maxSubArray(int[] nums) {        
        int tmp = 0;
        int res = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            tmp += nums[i];
            if (tmp > res)
                res = tmp;
            if (tmp < 0)
                tmp = 0;
        }
        return res;        
    }
}