class Solution {
    public int findMin(int[] nums) {
        int begin = 0, end = nums.length - 1;
        while (begin < end) {
            int mid = begin + (end - begin) / 2;
            if (nums[mid] < nums[end])
                end = mid;
            else if (nums[mid] > nums[end])
                begin = mid + 1;
            else
                end -= 1;
        }
        return nums[begin];
    }
}