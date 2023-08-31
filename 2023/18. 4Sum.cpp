class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int start, long long target) {
        int i = start, j = (int)nums.size() - 1;
        vector<vector<int>> ret;
        while (i < j) {
            if (nums[i] + nums[j] == target) {
                ret.push_back({nums[i], nums[j]});
                i++;
                j--;
                while (i < j && nums[i] == nums[i - 1]) {
                    i++;
                }
                while (i < j && nums[j] == nums[j + 1]) {
                    j--;
                }
            } else if (nums[i] + nums[j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return ret;
    }

    vector<vector<int>> fourSum(vector<int>& nums, long long target) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < (int)nums.size() - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                vector<vector<int>> two_sums = twoSum(nums, j + 1, target - nums[i] - nums[j]);
                for (vector<int>& ts : two_sums) {
                    ret.push_back({nums[i], nums[j], ts[0], ts[1]});
                }
            }
        }
        return ret;
    }
};