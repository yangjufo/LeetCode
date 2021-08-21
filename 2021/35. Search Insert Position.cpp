class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }        
        return left;
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = (int) nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;            
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left] < target ? left + 1 : left;
    }
};