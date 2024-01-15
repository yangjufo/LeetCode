class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int prev2 = nums[0], prev1 = max(nums[0], nums[1]);
        for (int i = 2; i + 1 < nums.size(); i++) {
            int curr = max (prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        int cand = max(prev1, prev2);
        if (nums.size() == 2) {
            return cand;
        }
        prev2 = nums[1];
        prev1 = max(nums[1], nums[2]);
        for (int i = 3; i < nums.size(); i++) {
            int curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return max(cand, max(prev2, prev1));
    }
};