class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        if (n < 2)
            return 0;
        int currMax = 0, nextMax = 0, i = 0, level = 0;
        while (currMax - i + 1 > 0) {
            level += 1;
            for (; i <= currMax; i++) {
                nextMax = Math.max(nextMax, nums[i] + i);
                if (nextMax >= n - 1)
                    return level;
            }
            currMax = nextMax;
        }
        return 0;
    }
}
