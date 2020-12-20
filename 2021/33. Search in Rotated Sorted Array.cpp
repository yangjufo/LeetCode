class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left / 2 + right / 2;
            if (nums[mid] > nums.back()) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        int realStart = left;        
        left = 0;
        right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int realMid = (mid + realStart) % nums.size();
            if (nums[realMid] == target) return realMid;
            if (nums[realMid] < target) left = mid + 1;
            else right = mid - 1;
        }
        
        return -1;
    }
};