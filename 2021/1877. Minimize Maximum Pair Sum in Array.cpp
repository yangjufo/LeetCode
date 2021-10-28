class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxSum = INT_MIN;
        for (int i = 0; i < (int)nums.size() / 2; i++) {
            maxSum = max(maxSum, nums[i] + nums[(int)nums.size() - 1 - i]);
        }
        return maxSum;
    }
};