class NumArray {

    int[] preSum;

    public NumArray(int[] nums) {
        preSum = new int[nums.length];
        if (nums.length != 0)
            preSum[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            preSum[i] = preSum[i - 1] + nums[i];
        }
    }

    public void update(int i, int val) {
        int old = 0;
        if (i == 0)
            old = preSum[0];
        else
            old = preSum[i] - preSum[i - 1];
        for (int k = i; k < preSum.length; k++) {
            preSum[k] = preSum[k] - old + val;
        }
    }

    public int sumRange(int i, int j) {
        if (i == 0)
            return preSum[j];
        else
            return preSum[j] - preSum[i - 1];
    }
}

/**
 * Your NumArray object will be instantiated and called as such: NumArray obj = new NumArray(nums);
 * obj.update(i,val); int param_2 = obj.sumRange(i,j);
 */
