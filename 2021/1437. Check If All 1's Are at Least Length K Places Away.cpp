class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int lastIndex = 0;
        while (lastIndex < nums.size() && nums[lastIndex] == 0) {
            lastIndex++;
        }
        for (int i = lastIndex + 1; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (i - lastIndex <= k) return false;
                lastIndex = i;
            }
        }
        return true;
    }
};