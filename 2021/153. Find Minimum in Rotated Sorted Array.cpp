class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int mid = 0;
        while (left < right) {
            mid = left / 2 + right / 2;
            if (nums[mid] > nums.back()) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};


class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums.back()) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = (int) nums.size() - 1;        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums.back()) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = (int)nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums.back()) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = (int) nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums.back()) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};