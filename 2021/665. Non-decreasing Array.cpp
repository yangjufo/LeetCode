class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int modCount = 0;
        for (int i = 0; i + 1 < nums.size() && modCount < 2; i++) {
            if (nums[i] > nums[i + 1]) {
                modCount++;
                if (i == 0 || nums[i + 1] >= nums[i - 1]) {
                    nums[i] = nums[i + 1];
                } else {
                    nums[i + 1] = nums[i];
                }
            }
        }
        return modCount < 2;
    }
};