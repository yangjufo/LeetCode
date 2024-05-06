class Solution {
    public int minimumSwaps(int[] nums) {
        int minIndex = 0, maxIndex = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }
            if (nums[i] >= nums[maxIndex]) {
                maxIndex = i;
            }
        }
        if (minIndex > maxIndex) {
            minIndex -= 1;
        }

        return minIndex + nums.length - 1 - maxIndex;
    }
}