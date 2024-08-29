class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int start, int target) {
        int end = nums.size() - 1;
        vector<vector<int>> res;
        while (start < end) {
            if (nums[start] + nums[end] == target) {
                res.push_back({nums[start], nums[end]});
                while (start < end && nums[start] == nums[start + 1]) {
                    start += 1;
                }
                while (start < end && nums[end] == nums[end - 1]) {
                    end -= 1;
                }
                start += 1;
                end -= 1;
            } else if (nums[start] + nums[end] > target) {
                end -= 1;
            } else {
                start += 1;
            }
        }
        return res;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            vector<vector<int>> twoRes = twoSum(nums, i + 1, 0 - nums[i]);
            for (vector<int>& t : twoRes) {
                res.push_back({nums[i], t[0], t[1]});
            }
        }
        return res;
    }
};