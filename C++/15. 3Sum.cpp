class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int lo, hi, sum;
        if (nums.size() < 3)
            return res;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                lo = i + 1;
                hi = static_cast<int>(nums.size() - 1);
                sum = 0 - nums[i];
                while (lo < hi) {
                    if (nums[lo] + nums[hi] == sum) {
                        res.emplace_back(vector<int>{nums[i], nums[lo], nums[hi]});
                        while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
                        while (lo < hi && nums[hi] == nums[hi - 1]) hi--;
                        lo++;
                        hi--;
                    } else if (nums[lo] + nums[hi] < sum) {
                        while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
                        lo++;
                    } else {
                        while (lo < hi && nums[hi] == nums[hi - 1]) hi--;
                        hi--;
                    }
                }
            }
        }
        return res;
            
    }
};