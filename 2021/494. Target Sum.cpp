class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> curr = {{0, 1}};
        return backtrack(curr, nums, 0, target);
    }
    
    int backtrack(unordered_map<int, int>& prev, vector<int>& nums, int index, int target) {
        if (index >= nums.size()) {
            return prev[target];
        }
        unordered_map<int, int> curr;
        for (auto& iter : prev) {
            curr[iter.first + nums[index]] += iter.second;
            curr[iter.first - nums[index]] += iter.second;
        }
        return backtrack(curr, nums, index + 1, target);
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int s) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum < s || (s + sum) & 1 ? 0 : subsetSum(nums, (s + sum) >> 1); 
    }   

    int subsetSum(vector<int>& nums, int s) {
        vector<int> dp(s + 1);
        dp[0] = 1;
        for (int n : nums)
            for (int i = s; i >= n; i--)
                dp[i] += dp[i - n];
        return dp[s];
    }
};