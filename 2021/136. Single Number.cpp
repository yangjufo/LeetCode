class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int rem = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            rem ^= nums[i];
        }
        return rem;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            res ^= nums[i];
        }
        return res;
    }
};