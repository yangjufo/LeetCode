class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0, sum = 0, minLen = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum - nums[start] >= target) {
                sum -= nums[start];
                start += 1;
            }
            if (sum >= target) {
                minLen = min(minLen, i - start + 1);
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};