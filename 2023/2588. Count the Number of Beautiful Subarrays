class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> preSum(n + 1);
        for (int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i];
            for (int j = 0; j < 20; j++) {
                if ((nums[i] & (1 << j)) != 0) {
                    preSum[i + 1] ^= ((1 << j));
                }
            }
        }
        long long count = 0;
        map<int, int> count_map;
        for (int i = 0; i < preSum.size(); i++) {
            count += count_map[preSum[i]];
            count_map[preSum[i]] += 1;
        }

        return count;
    }
};