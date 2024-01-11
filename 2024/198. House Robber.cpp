class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int prev2 = nums[0], prev1 = nums[1];
        for (int i = 2; i < nums.size(); i++) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = max(prev1, prev2);
            prev1 = curr;
        }
        return max(prev1, prev2);
    }
};