class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, maxLen = 0;
        for (int n : nums) {
            if (n == 1) {
                count++;
            } else {
                maxLen = max(maxLen, count);
                count = 0;
            }
        }
        return max(maxLen, count);
    }
};