class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = nums[0], minSum = nums[0], currMax = 0, currMin = 0, totalSum = 0;
        for (int n : nums) {
            currMax = max(currMax + n, n);
            currMin = min(currMin + n, n);
            maxSum = max(maxSum, currMax);
            minSum = min(minSum, currMin);
            totalSum += n;
        }
        return maxSum > 0 ? max(maxSum, totalSum - minSum) : maxSum;
    }
};