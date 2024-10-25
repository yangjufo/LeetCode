class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size(), totalSum = 0;
        for (int n : nums) {
            totalSum = (totalSum + n) % p;
        }
        int target = totalSum % p;
        if (target == 0) {
            return 0;
        }
        unordered_map<int, int> mods = {{0, -1}};
        int sum = 0, minLen = n;
        for (int i = 0; i < n; ++i) {
            sum = (sum + nums[i]) % p;
            int needed = (sum - target + p) % p;
            if (mods.find(needed) != mods.end()) {
                minLen = min(minLen, i - mods[needed]);
            }
            mods[sum] = i;
        }
        return minLen == n ? -1 : minLen;
    }
};