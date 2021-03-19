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