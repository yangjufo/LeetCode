class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        while (left < nums.size() && nums[left] < 0) {
            left++;
        }
        left--;
        int right = left + 1;
        vector<int> res;
        while (left >= 0 || right < nums.size()) {
            if (left < 0 || (right < nums.size() && nums[right] < -nums[left])) {
                res.push_back(nums[right] * nums[right]);
                right++;
            } else {
                res.push_back(nums[left] * nums[left]);
                left--;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0, right = (int) nums.size() - 1, index = right;
        vector<int> res(nums.size());
        while (left <= right) {
            int leftR = nums[left] * nums[left];
            int rightR = nums[right] * nums[right];            
            if (leftR > rightR) {
                res[index] = leftR;
                left++;
            } else {
                res[index] = rightR;
                right--;
            }
            index--;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int left = 0, right = (int) nums.size() - 1, index = (int)nums.size() - 1;
        while (left <= right) {
            if (nums[left] * nums[left] < nums[right] * nums[right]) {
                res[index] = nums[right] * nums[right];
                right--;
            } else {
                res[index] = nums[left] * nums[left];
                left++;
            }
            index--;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int left = 0, right = (int) nums.size() - 1, index = (int)nums.size() - 1;
        while (left <= right) {
            if (abs(nums[left]) < abs(nums[right])) {
                res[index] = nums[right] * nums[right];
                right--;
            } else {
                res[index] = nums[left] * nums[left];
                left++;
            }
            index--;
        }
        return res;
    }
};