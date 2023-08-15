class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_indexes;
        for (int i = 0; i < nums.size(); i++) {
            if (num_indexes.find(target - nums[i]) != num_indexes.end()) {
                return {i, num_indexes[target - nums[i]]};
            }
            num_indexes[nums[i]] = i;
        }
        return {};
    }
};