class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int tmp_target1, tmp_target2, lo, hi;
        auto N = static_cast<int>(nums.size());
        for (int i = 0; i < N; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            tmp_target1 = target - nums[i];
            for (int j = i + 1; j < N; j++) {
                if (nums[j] == nums[j - 1] && j != i + 1)
                    continue;
                tmp_target2 = tmp_target1 - nums[j];
                lo = j + 1;
                hi = N - 1;
                while (lo < hi) {
                    if (nums[lo] + nums[hi] == tmp_target2) {
                        res.push_back(vector<int>{nums[i], nums[j], nums[lo], nums[hi]});
                        while (nums[lo] == nums[lo + 1])
                            lo++;
                        lo++;
                        while (nums[hi] == nums[hi - 1])
                            hi--;
                        hi--;
                    } else if (nums[lo] + nums[hi] > tmp_target2) {
                        while (nums[hi] == nums[hi - 1])
                            hi--;
                        hi--;
                    } else {
                        while (nums[lo] == nums[lo + 1])
                            lo++;
                        lo++;
                    }
                }
            }
        }
        return res;
    }

};