class Solution {
    int ans;

    public int threeSumSmaller(int[] nums, int target) {
        Arrays.sort(nums);
        int sum = 0;
        for (int i = 0; i < nums.length - 2; i++) {
            sum += twoSumSmaller(nums, i + 1, nums.length - 1, target - nums[i]);
        }
        return sum;
    }

    private int twoSumSmaller(int[] nums, int start, int end, int target) {
        int sum = 0;
        while (start < end) {
            if (nums[start] + nums[end] < target) {
                sum += end - start;
                start += 1;
            } else
                end -= 1;
        }
        return sum;
    }
}
