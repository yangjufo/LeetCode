class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {            
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp.back();
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0, prev1 = 0;
        for (int n : nums) {
            int curr = max(prev1, prev2 + n);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};