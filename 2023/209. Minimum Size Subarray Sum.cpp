class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0, minLen = nums.size() + 1, sum = 0, index = 0;
        while (index < nums.size()) {
            sum += nums[index];
            while (start < index && sum - nums[start] >= target) {
                sum -= nums[start];
                start++;
            }
            if (sum >= target) {
                minLen = min(minLen, index - start + 1);
            }
            index++;
        }
        return minLen > nums.size() ? 0 : minLen;
    }
};