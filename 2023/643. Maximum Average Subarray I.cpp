class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0, maxSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (i == k - 1) {
                maxSum = sum;
            } else if (i >= k) {
                sum -= nums[i - k];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum * 1.0 / k;
    }
};