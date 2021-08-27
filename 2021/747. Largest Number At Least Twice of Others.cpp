class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int twiceMax = 0, maxIndex = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[maxIndex]) {
                twiceMax = nums[maxIndex] * 2;
                maxIndex = i;
            } else if (nums[i] * 2 > twiceMax) {
                twiceMax = nums[i] * 2;
            }
        }
        return nums[maxIndex] >= twiceMax ? maxIndex : -1;
    }
};