class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = nums[0];
        int tmp = 0;
        for (int i = 0; i < nums.size(); i++) {
            tmp += nums[i];
            res = tmp > res ? tmp : res;
            tmp = tmp < 0 ? 0 : tmp;            
        }
        return res;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        return maxSubSum(nums, 0, nums.size() - 1);
    }
    
    int maxSubSum(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return nums[left];
        }
        
        int mid = left / 2 + right / 2;
        
        int leftSubSum = maxSubSum(nums, left, mid);
        int rightSubSum = maxSubSum(nums, mid + 1, right);
        int crossSubSum = maxCrossSubSum(nums, left, right, mid);
        return max(max(leftSubSum, rightSubSum), crossSubSum);
    }
    
    int maxCrossSubSum(vector<int>& nums, int left, int right, int mid) {                
        int leftSum = nums[mid], rightSum = nums[mid + 1];        
        
        int tmpSum = 0;
        for (int i = mid; i > -1; i--) {
            tmpSum += nums[i];
            leftSum = tmpSum > leftSum ? tmpSum : leftSum;
        }
        
        tmpSum = 0;
        for (int i = mid + 1; i <= right; i++) {
            tmpSum += nums[i];
            rightSum = tmpSum > rightSum ? tmpSum : rightSum;
        }
        
        return leftSum + rightSum;        
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, sum = 0;        
        for (int n : nums) {
            sum += n;
            maxSum = max(sum, maxSum);
            sum = max(sum, 0);
        }
        return maxSum;
    }
};