class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }
        int start = 0, target = sum - x, maxLen = -1, currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            while (start <= i && currSum > target) {
                currSum -= nums[start];
                start++;
            }
            if (currSum == target) {
                maxLen = max(maxLen, i - start + 1);
            }
        }
        return maxLen == -1 ? -1 : ((int)nums.size() - maxLen);
    }
};