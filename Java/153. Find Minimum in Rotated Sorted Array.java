class Solution {
    public int findMin(int[] nums) {
        int start = 0, end = nums.length - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if ((mid == 0 || nums[mid] < nums[mid - 1]) && (mid == nums.length - 1 || nums[mid] < nums[mid + 1]))
                return nums[mid];               
            else if(mid == 0 || nums[mid] > nums[nums.length - 1])
                start = mid + 1;                        
            else
                end = mid - 1;
        }
        return nums[start];
    }
}