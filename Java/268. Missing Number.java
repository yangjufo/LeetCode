class Solution {
    public int missingNumber(int[] nums) {
        int res = nums.length;
        for (int i = 0; i < nums.length; i++)
            res ^= nums[i] ^ i;                
        return res;
    }
}