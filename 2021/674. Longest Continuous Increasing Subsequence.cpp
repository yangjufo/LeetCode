class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxLen = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] > nums[i - 1]) {
                count++;
            } else {
                count = 1;
            }
            maxLen = max(maxLen, count);
        }
        return maxLen;
    }
};