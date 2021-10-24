class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int diff = 0;
        for (int i = 1; i < nums.size(); i++) {           
            if (nums[i] - nums[i - 1] != 0) {
                if (diff == 0) {
                    diff = nums[i] > nums[i - 1] ? 1 : -1;
                } else {
                    if (diff * (nums[i] - nums[i - 1]) < 0) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};