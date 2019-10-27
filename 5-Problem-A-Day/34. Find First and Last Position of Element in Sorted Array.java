class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] ans = {-1, -1};
        int left = 0, right = nums.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        if (left == nums.length || nums[left] != target)
            return ans;
        ans[0] = left;
        left = 0;
        right = nums.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target)
                right = mid;
            else
                left = mid + 1;
        }
        ans[1] = left - 1;
        return ans;
    }
}
