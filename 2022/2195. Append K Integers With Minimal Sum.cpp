class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int unique = 0;
        long long preSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            preSum += nums[i];
            unique++;
            if (nums[i] >= unique + k) {
                preSum = preSum - nums[i] + unique + k;
                break;
            }
        }
        long long sum = (long long)(1 + unique + k) * (unique + k) / 2;
        return sum - preSum;
    }
};