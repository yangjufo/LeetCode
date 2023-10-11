class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        vector<long long> pre_or(nums.size()), suf_or(nums.size());
        for (int i = 1; i < nums.size(); i++) {
            pre_or[i] = pre_or[i - 1] | nums[i - 1];
        }
        for (int i = (int)nums.size() - 2; i >= 0; i--) {
            suf_or[i] = suf_or[i + 1] | nums[i + 1];
        }
        long long res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res = max(res, pre_or[i] | ((long long)nums[i] << k) | suf_or[i]);
        }
        return res;
    }
};