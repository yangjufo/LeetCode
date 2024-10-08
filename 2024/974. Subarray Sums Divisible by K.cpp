class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mods;
        mods[0] = 1;
        int sum = 0, total = 0;
        for (int n : nums) {
            sum = (sum + n % k + k) % k;
            total += mods[sum];
            mods[sum] += 1;
        }
        return total;
    }
};