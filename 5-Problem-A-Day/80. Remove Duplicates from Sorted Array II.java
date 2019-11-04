class Solution {
    public int removeDuplicates(int[] nums) {
        int start = 0, count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i == 0 || nums[i] == nums[i - 1])
                count += 1;
            else
                count = 1;
            if (count <= 2)
                nums[start++] = nums[i];
        }
        return start;
    }
}
