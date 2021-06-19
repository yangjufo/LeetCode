class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int start = -1, dp = 0, total = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] < left) {
                total += dp;
            } else if (nums[i] > right) {
                dp = 0;
                start = i;
            } else if (nums[i] >= left && nums[i] <= right) {
                dp = i - start;
                total += dp;
            }
        }
        return total;
    }    
};

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int prev = -1, dp = 0, total = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < left) {
                total += dp;
            } else if (nums[i] > right) {
                prev = i;
                dp = 0;                     
            } else if (nums[i] >= left && nums[i] <= right) {
                dp = i - prev;
                total += dp;
            }
        }
        return total;
    }
};