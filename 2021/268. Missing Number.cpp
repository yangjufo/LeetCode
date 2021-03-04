class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            ans ^= nums[i] ^ i;
        }
        return ans;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0 ^ nums[0], N = nums.size();
        for (int i = 1; i < nums.size(); i++) {
            res ^= i ^ nums[i];
        }
        return res ^ N;
    }
};