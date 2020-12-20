#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIndexMap;
        for (int i = 0; i < nums.size(); i++) {
            if (numIndexMap.count(target - nums[i])) {
                return {numIndexMap[target - nums[i]], i};
            }
            numIndexMap[nums[i]] = i;
        }
        return {};
    }
};