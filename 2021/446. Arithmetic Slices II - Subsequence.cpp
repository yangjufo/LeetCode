class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<unordered_map<long long, int>> diff(nums.size());
        long long count = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {                
                if (diff[j].find((long long)nums[i] - nums[j]) != diff[j].end()) {
                    diff[i][(long long)nums[i] - nums[j]] += diff[j][(long long)nums[i] - nums[j]] + 1;
                    count += diff[j][(long long)nums[i] - nums[j]];
                } else {
                    diff[i][(long long)nums[i] - nums[j]]++;
                }
            }            
        }
        return count;
    }
};

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<unordered_map<long long, int>> dp(nums.size());
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                long long diff = (long long)nums[i] - nums[j];
                if (dp[j].find(diff) != dp[j].end()) {
                    count += dp[j][diff];
                    dp[i][diff] += dp[j][diff];
                }
                dp[i][diff] += 1;                
            }
        }
        return count;
    }
};