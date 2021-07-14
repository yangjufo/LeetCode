class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                if ((i < nums.size() - 1 && nums[i] > nums[i + 1]) || i == nums.size() - 1) {
                    return i;
                }
            } 
            else if (i == nums.size() - 1) {
                if (nums[i] > nums[i - 1]) return i;
            } else {
                if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) return i;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;            
            if ((mid == 0 && nums[mid] > nums[mid + 1]) || (mid == nums.size() -1 && nums[mid] > nums[mid - 1]) || (mid > 0 && mid < nums.size() - 1 && nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])) return mid;
            if (mid == 0 || nums[mid] > nums[mid - 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {        
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;                        
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {            
            int mid = left + (right - left) / 2;            
            if (mid + 1 < nums.size() && nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};