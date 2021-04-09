class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> indexes;
        for (int i = 0; i < nums.size(); i++) {
            if (indexes.find(nums[i]) != indexes.end() && (i - indexes[nums[i]]) <= k) {
                return true;
            }
            indexes[nums[i]] = i;
        }
        return false;
    }
};