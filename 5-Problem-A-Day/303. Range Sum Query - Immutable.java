class NumArray {

    int[] nums;
    
    public NumArray(int[] nums) {
        this.nums = nums;
    }
    
    public int sumRange(int i, int j) {
        int ans = 0;
        for (int k = i; k <= j; k++)
            ans += nums[k];
        return ans;
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */