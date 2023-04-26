class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> counts(101), res;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) {
                counts[nums[i - k] + 50] -= 1;
            }
            counts[nums[i] + 50] += 1;
            if (i < k - 1) {
                continue;
            }
            int c = 0, r = -1;
            while (c < x) {
                r++;
                c += counts[r];
            }
            res.push_back((r - 50) < 0 ? (r - 50) : 0);
        }
        return res;
    }
};