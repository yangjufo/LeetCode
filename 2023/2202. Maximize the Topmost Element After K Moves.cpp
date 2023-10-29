class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if (k == 0) {
            return nums[0];
        }
        if (k == 1) {
            return nums.size() == 1 ? -1 : nums[1];
        }
        if (nums.size() == 1) {
            return k % 2 == 0 ? nums[0] : -1;
        }
        int cand = INT_MIN;
        for (int i = 0; i < k - 1 && i < nums.size(); i++) {
            cand = max(cand, nums[i]);
        }
        if (k < nums.size()) {
            return max(cand, nums[k]);
        }
        return cand;
    }
};