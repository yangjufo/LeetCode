class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int maxSum = 0, sum = 0, afterSum = 0;
        for (int n : nums) {            
            afterSum = max(afterSum + n, sum + n * n);
            sum += n;
            maxSum = max(max(maxSum, afterSum), sum);
            sum = max(sum, 0);
        }
        return maxSum;
    }
};