class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {            
            while (left < right && nums[left] == nums[left + 1]) {
                left++;
            }
            while (left < right && nums[right] == nums[right - 1]) {
                right--;
            }            
            int mid = left + (right - left) / 2;
            if (nums[mid] >= nums.back()) {
                left = mid + 1;
            } else {
                right = mid;
            }            
        }
        return left >= nums.size() ? nums.back() : nums[left];
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = (int) nums.size() - 1;
        while (left < right) {
            while (left < right && nums[left] == nums[left + 1]) {
                left++;
            }
            while (left < right && nums[right] == nums[right - 1]) {
                right--;
            }
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }            
        }
        return nums[left];
    }
};