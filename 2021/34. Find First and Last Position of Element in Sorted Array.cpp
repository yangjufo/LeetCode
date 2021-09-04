class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1, -1};
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        if (left < nums.size() && nums[left] == target) {
            res[0] = left;                                                
            left = 0, right = nums.size() - 1;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] <= target) {
                    left = mid + 1;
                } else {
                    right = mid;
                }                
            }
            res[1] = nums[left] == target ? left : left - 1;
        }
        
        return res;
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (left >= nums.size() || nums[left] != target) {
            return {-1, -1};
        }
        res.push_back(left);
        
        left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        res.push_back(nums[left] == target ? left : left - 1);
        return res;
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = (int)nums.size() - 1;
        vector<int> res;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (left < nums.size() && nums[left] == target) res.push_back(left);
        else return {-1, -1};
        
        left = 0, right = (int)nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;            
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }            
        }        
        if (nums[left] == target) res.push_back(left);
        else res.push_back(left - 1);
        return res;
    }        
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto left = lower_bound(nums.begin(), nums.end(), target);
        if (left == nums.end() || *left != target) return {-1, -1};
        return {(int)(left - nums.begin()), (int)(upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1)};        
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int startPos = -1, left = 0, right = (int)nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (left >= nums.size() || nums[left] != target) return {-1, -1};
        startPos = left;
        left = 0, right = (int)nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int endPos = nums[left] == target ? left : left - 1;
        return {startPos, endPos};
    }
};
