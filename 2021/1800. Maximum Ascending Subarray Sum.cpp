class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = nums[0], curr = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                curr += nums[i];
            } else {
                curr = nums[i];
            }
            maxSum = max(maxSum, curr);
        }
        return maxSum;
    }
};