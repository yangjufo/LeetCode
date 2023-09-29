class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int diff = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (diff == 0 && (nums[i] - nums[i - 1]) != 0) {
                diff = nums[i] - nums[i - 1];
            } else if ((nums[i] - nums[i - 1] < 0 && diff > 0) || (diff < 0 && nums[i] - nums[i - 1] > 0)) {
                return false;
            }
        }
        return true;
    }
};