class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int index, int target) {
        int left = index, right = (int)nums.size() - 1;
        vector<vector<int>> triplets;
        while (left < right) {
            if (nums[left] + nums[right] == target) {
                triplets.push_back({nums[left], nums[right], -target});
                left++;
                right--;
                while (left < right && nums[left] == nums[left - 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right + 1]) {
                    right--;
                }
            } else if (nums[left] + nums[right] < target) {
                left++;
            } else {
                right--;
            }
        }
        return triplets;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            vector<vector<int>> tmp = twoSum(nums, i + 1, -nums[i]);
            for (vector<int>& p : tmp) {
                triplets.push_back(p);
            }
        }
        return triplets;
    }
};