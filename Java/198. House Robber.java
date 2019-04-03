class Solution {
    public int rob(int[] nums) {        
        int pre = 0, curr = 0;
        for (int x : nums) {
            int tmp = curr;
            curr = Math.max(pre + x, curr);
            pre = tmp;
        }            
        return curr;
    }
}