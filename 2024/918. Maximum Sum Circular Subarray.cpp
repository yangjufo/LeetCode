class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int minSum = nums[0], maxSum = nums[0], currMin = 0, currMax = 0, totalSum = 0;
        for (int n : nums) {
            currMin = min(currMin + n, n);
            currMax = max(currMax + n, n);
            maxSum = max(currMax, maxSum);
            minSum = min(currMin, minSum);
            totalSum += n;
        }
        return maxSum > 0 ? max(maxSum, totalSum - minSum) : maxSum;
    }
};