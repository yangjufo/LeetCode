class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxSum = INT_MIN;
        for (int n : nums) {
            sum += n;
            maxSum = max(maxSum, sum);
            sum = max(sum, 0);
        }
        return maxSum;
    }
};