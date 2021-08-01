class Solution {
public:
    int mod = 1'000'000'007;
    int countSpecialSubsequences(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(3, 0));           
        for (int i = 0; i < nums.size(); i++) {            
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = dp[i][1];
            dp[i + 1][2] = dp[i][2];
            if (nums[i] == 0) {
                dp[i + 1][0] = ((dp[i][0] + 1) % mod + dp[i][0]) % mod;
            } else if (nums[i] == 1) {
                dp[i + 1][1] = ((dp[i][0] + dp[i][1]) % mod + dp[i][1]) % mod;
            } else if (nums[i] == 2) {
                dp[i + 1][2] = ((dp[i][1] + dp[i][2]) % mod + dp[i][2]) % mod;                
            }
        }
        return dp[nums.size()][2];
    }
};