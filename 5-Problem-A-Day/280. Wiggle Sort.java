class Solution {
    public void wiggleSort(int[] nums) {
        boolean less = true;
        for (int i = 0; i < nums.length - 1; i++) {
            if (less) {
                if (nums[i] > nums[i + 1])
                    swap(nums, i, i + 1);
            } else {
                if (nums[i] < nums[i + 1])
                    swap(nums, i, i + 1);
            }
            less = !less;
        }
    }
    
    private void swap(int[] nums, int left, int right) {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
    }
}