class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int minDiff = nums.back() - nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k - 1) {
                minDiff = min(minDiff, nums[i] - nums[i - k + 1]);
            }
        }
        return minDiff;
    }
};