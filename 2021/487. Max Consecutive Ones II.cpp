class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int zeroCount = 0, start = 0, maxLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zeroCount++;
            }
            while (zeroCount > 1) {
                if (nums[start] == 0) {
                    zeroCount--;
                }
                start++;
            }
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};