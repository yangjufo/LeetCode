class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        stack<int> minIndex;
        minIndex.push(-1);
        vector<long> preSum(nums.size() + 1, 0);
        long res = 0;
        for (int i = 0; i < nums.size(); i++) {
            preSum[i + 1] = preSum[i] + nums[i];
            while (minIndex.top() != -1 && nums[i] < nums[minIndex.top()]) {
                int currIndex = minIndex.top();
                minIndex.pop();
                res = max(res, nums[currIndex] * (preSum[i] - preSum[minIndex.top() + 1]));
            }
            minIndex.push(i);
        }
        
        while (minIndex.top() != -1) {
            int currIndex = minIndex.top();
            minIndex.pop();
            res = max(res, nums[currIndex] * (preSum.back() - preSum[minIndex.top() + 1]));
        }
        return res % 1'000'000'007;
    }
};