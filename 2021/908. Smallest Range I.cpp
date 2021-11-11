class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int maxVal = nums[0], minVal = nums[0];
        for (int n : nums) {
            maxVal = max(maxVal, n);
            minVal = min(minVal, n);
        }
        return max(maxVal - minVal - 2 * k, 0);
    }
};