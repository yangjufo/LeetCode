class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int count = 0, maxLen = 1;
        vector<pair<int, int>> dp(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            dp[i] = {1, 1};
            if (maxLen == 1) {
                count++;
            }
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {                    
                    if (dp[j].first + 1 >= dp[i].first) {
                        if (dp[j].first + 1 > dp[i].first) {
                            dp[i].second = 0;
                        }
                        dp[i].first = dp[j].first + 1;
                        dp[i].second += dp[j].second;
                        if (dp[i].first > maxLen) {
                            maxLen = dp[i].first;
                            count = dp[i].second;
                        } else if (dp[i].first == maxLen) {
                            count += dp[j].second;
                        }
                    }                   
                } 
            }                       
        }
        return count;
    }
};