class Solution {
    public int maxSubArray(int[] nums) {
        int sum = nums[0];              
        int tmp = 0;
        for (int i : nums) {
            tmp += i;
            sum = Math.max(sum, tmp);
            tmp = Math.max(tmp, 0);                
        }
        return sum;
    }
}