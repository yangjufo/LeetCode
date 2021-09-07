class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int posMaxLen = 1, negMaxLen = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] < 0) {
                negMaxLen = posMaxLen + 1;
            } else if (nums[i] - nums[i - 1] > 0) {
                posMaxLen = negMaxLen + 1;
            }
        }
        return max(negMaxLen, posMaxLen);
    }
};

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<pair<int, int>> dp(nums.size());
        dp[0] = {1, 1};
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i].first = max(dp[i].first, dp[j].second + 1);
                } else if (nums[i] < nums[j]) {
                    dp[i].second = max(dp[i].second, dp[j].first + 1);
                }
            }
            res = max(res, max(dp[i].first, dp[i].second));
        }
        return res;
    }
};