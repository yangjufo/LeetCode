class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res(nums.size());
        for (int i = 0, j = 0; i < nums.size(); i += 2, j++) {
            res[i] = nums[j];
        }
        for (int i = 1, j = nums.size() / 2; i < nums.size(); i += 2, j++) {
            res[i] = nums[j];
        }
        return res;
    }
};