class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if (nums.size() == 1) {
            return k % 2 == 0 ? nums[0] : -1;
        }

        int maxVal = 0;
        for (int i = 0; i + 1 < k && i < nums.size(); i++) {
            maxVal = max(nums[i], maxVal);
        }
        if (nums.size() > k) {
            maxVal = max(nums[k], maxVal);
        }
        return maxVal;
    }
};