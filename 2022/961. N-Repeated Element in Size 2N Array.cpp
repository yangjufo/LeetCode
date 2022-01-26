class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> numSet;
        for (int n : nums) {
            if (numSet.find(n) != numSet.end()) {
                return n;
            }
            numSet.insert(n);
        }
        return -1;
    }
};

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] || nums[i] == nums[i - 2]) {
                return nums[i];
            }
        }
        return nums[0];
    }
};