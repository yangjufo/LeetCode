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

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> preNums;
        for (int i = 0; i < nums.size(); i++) {
            if (preNums.find(target - nums[i]) != preNums.end()) {
                return {i, preNums[target - nums[i]]};
            }
            preNums[nums[i]] = i;
        }
        return {};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); i++) {
            if (numMap.find(target - nums[i]) != numMap.end()) {
                return {numMap[target - nums[i]], i};
            }
            numMap[nums[i]] = i;
        }
        return {};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); i++) {
            if (seen.find(target - nums[i]) != seen.end()) {
                return {seen[target - nums[i]], i};
            }
            seen[nums[i]] = i;
        }
        return {-1, -1};
    }
};