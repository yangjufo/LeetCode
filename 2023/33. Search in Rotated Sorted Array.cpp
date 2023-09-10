class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = (int)nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums.back()) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int start = left;

        left = 0, right = (int)nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int realMid = (start + mid) % nums.size();
            if (nums[realMid] < target) {
                left = mid + 1;
            } else if (nums[realMid] > target) {
                right = mid - 1;
            } else {
                return realMid;
            }
        }
        return -1;
    }
};