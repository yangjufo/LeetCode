class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = 0;
        for (int n : nums) {
            target += n;
        }
        target -= x;
        if (target < 0) return -1;
        int start = 0, maxLen = -1, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum > target) {
                sum -= nums[start];
                start++;
            }
            if (sum == target) {
                maxLen = max(maxLen, i - start + 1);
            }
        }
        return maxLen == -1 ? -1 : nums.size() - maxLen;
    }
};