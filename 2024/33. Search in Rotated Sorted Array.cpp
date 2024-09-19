class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= nums.back()) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        int start = left;
        left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int realMid = (start + mid) % nums.size();
            if (nums[realMid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[(start + left) % nums.size()] == target ? (start + left) % nums.size() : -1;
    }
};