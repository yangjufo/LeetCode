class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        return divide(nums, 0, (int) nums.size() - 1);
    }
    
    int divide(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }
        int mid = left + (right - left) / 2;
        if (mid % 2 == 0) {
            if (mid > 0 && nums[mid] == nums[mid - 1]) {
                return divide(nums, left, mid - 1);
            }
            if (mid + 1 < nums.size() && nums[mid] == nums[mid + 1]) {
                return divide(nums, mid + 1, right);
            }            
        } else {
            if (mid > 0 && nums[mid] == nums[mid - 1]) {
                return divide(nums, mid + 1, right);
            }
            if (mid + 1 < nums.size() && nums[mid] == nums[mid + 1]) {
                return divide(nums, left, mid - 1);
            }
        }
        return nums[mid];
    }
};

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = (int)nums.size() - 1;
        while (left < right) {                        
            int mid = left + (right - left) / 2;
            if (mid % 2 == 0) {
                if (mid > 0 && nums[mid] == nums[mid - 1]) {
                    right = mid - 1;
                }
                if (mid + 1 < nums.size() && nums[mid] == nums[mid + 1]) {
                    left = mid + 1;
                }            
            } else {
                if (mid > 0 && nums[mid] == nums[mid - 1]) {
                    left = mid + 1;
                }
                if (mid + 1 < nums.size() && nums[mid] == nums[mid + 1]) {
                    right = mid - 1;
                }
            }
            if (left + (right - left) / 2 == mid) return nums[mid];
        }
        return nums[left];
    }        
};