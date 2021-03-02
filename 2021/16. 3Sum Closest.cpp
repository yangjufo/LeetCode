class Solution {
public:    
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; i++) {
            int twoClosest = twoSumClosest(nums, i + 1, target - nums[i]);
            if (abs(nums[i] + twoClosest - target) < abs(res - target)) {
                res = nums[i] + twoClosest;
            }            
        }
        return res;
    }
    
    int twoSumClosest(vector<int>& nums, int start, int target) {
        int res = nums[start] + nums[start + 1], left = start, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];            
            if (sum > target) {
                right--;
            } else {
                left++;
            }
            if (abs(sum - target) < abs(res - target)) {
                res = sum;
            }
        }
        return res;
    }
};