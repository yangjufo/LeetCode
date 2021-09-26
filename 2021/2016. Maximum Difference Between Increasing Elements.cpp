class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDiff = -1, currMin = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            currMin = min(currMin, nums[i]);
            if (nums[i] > currMin) {
                maxDiff = max(maxDiff, nums[i] - currMin);
            }            
        }
        return maxDiff;
    }
};