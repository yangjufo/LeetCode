class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> numCount;
        for (int n : nums) {
            numCount[n]++;
        }

        int count = 0;
        for (auto iter : numCount) {
            if (k > 0 && numCount.find(iter.first + k) != numCount.end()) {
                count++;
            } else if (k == 0 && iter.second > 1) {
                count++;
            }
        }
        return count;
    }
};

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_set<int> numSet;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if ((k == 0 && i >= 2 && nums[i] == nums[i - 2]) || (k != 0 && i >= 1 && nums[i] == nums[i - 1])) {
                continue;
            }
            if (numSet.find(nums[i] - k) != numSet.end()) {
                count++;
            }
            numSet.insert(nums[i]);
        }
        return count;
    }
};