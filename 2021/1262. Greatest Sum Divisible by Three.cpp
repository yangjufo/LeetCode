class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {        
        int n = nums.size();
        int dp[n + 1][3];
        memset(dp, 0, sizeof(dp));
        dp[0][1] = INT_MIN;
        dp[0][2] = INT_MIN;
        for (int i = 0; i < n; i++) {
            int mod = nums[i] % 3;                        
            if (mod == 0) {
                dp[i + 1][0] = dp[i][0] + nums[i];
                dp[i + 1][1] = dp[i][1] + nums[i];
                dp[i + 1][2] = dp[i][2] + nums[i];
            }
            if (mod == 1) {
                dp[i + 1][0] = max(dp[i][0], dp[i][2] + nums[i]);
                dp[i + 1][1] = max(dp[i][1], dp[i][0] + nums[i]);
                dp[i + 1][2] = max(dp[i][2], dp[i][1] + nums[i]);
            }
            if (mod == 2) {
                dp[i + 1][0] = max(dp[i][0], dp[i][1] + nums[i]);
                dp[i + 1][1] = max(dp[i][1], dp[i][2] + nums[i]);
                dp[i + 1][2] = max(dp[i][2], dp[i][0] + nums[i]);
            }          
        }
        return dp[n][0];
    }
};

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp = {0, INT_MIN, INT_MIN}, prev = {0, INT_MIN, INT_MIN};
        for (int n : nums) {
            if (n % 3 == 0) {
                dp[0] = prev[0] + n;
                dp[1] = prev[1] + n;
                dp[2] = prev[2] + n;
            } else if (n % 3 == 1) {
                dp[0] = max(dp[0], prev[2] + n);
                dp[1] = max(dp[1], prev[0] + n);
                dp[2] = max(dp[2], prev[1] + n);
            } else {
                dp[0] = max(dp[0], prev[1] + n);
                dp[1] = max(dp[1], prev[2] + n);
                dp[2] = max(dp[2], prev[0] + n);
            }
            prev = dp;
        }
        return dp[0];
    }
};