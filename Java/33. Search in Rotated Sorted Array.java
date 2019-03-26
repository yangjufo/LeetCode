class Solution {
    public int search(int[] nums, int target) {
        int start = 0, end = nums.length - 1, mid = -1;
        int realStart = 0;
        while (start <= end) {
            mid = start + (end - start) / 2;            
            if ((mid == 0 || nums[mid] < nums[mid - 1]) && (mid == nums.length - 1 || nums[mid] < nums[mid + 1])) {                
                break;
            }
            if (nums[mid] > nums[nums.length - 1])
                start = mid + 1;
            else
                end = mid - 1;
        }        
        realStart = mid;
        start = 0;
        end = nums.length - 1;        
        while (start <= end) {
            mid = start + (end - start) / 2;
            int realMid = (mid + realStart) % nums.length;            
            if (nums[realMid] == target)
                return realMid;
            if (nums[realMid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }        
        return -1;        
    }
}