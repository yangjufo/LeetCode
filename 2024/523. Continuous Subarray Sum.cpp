class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> remains;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if ((sum % k == 0 && i > 0) || remains.find(sum % k) != remains.end()) {
                return true;
            }
            if (i > 0) {
                remains.insert((sum - nums[i]) % k);
            }
        }
        return false;
    }
};