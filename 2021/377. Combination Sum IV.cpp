class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);        
        dp[0] = 1;
        findOne(nums, target, dp);
        return dp[target];
    }
    
     int findOne(vector<int>& nums, int target, vector<int>& dp) {        
         if (dp[target] != -1) return dp[target];
         int count = 0;
         for (int num : nums) {
             if (num <= target) {
                 count += findOne(nums, target - num, dp);
             }
         }
         dp[target] = count;
         return count;
    }
};

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {            
            for (int n : nums) {
                if (n <= i) {
                    if (dp[i] > INT_MAX - dp[i - n]) {
                        dp[i] = INT_MAX;
                    } else {
                        dp[i] += dp[i - n];
                    }                    
                }
            }    
        }
        return dp[target];
    }
};