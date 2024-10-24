class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> preSum = {{0, 1}};
        int sum = 0, count = 0;
        for (int n : nums) {
            sum += n;
            count += preSum[sum - goal];
            preSum[sum] += 1;
        }
        return count;
    }
};

class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) {
            return 0;
        }
        int res = 0, start = 0;
        for (int i = 0; i < nums.size(); i++) {
            goal -= nums[i];
            while (goal < 0) {
                goal += nums[start];
                start += 1;
            }
            res += i - start + 1;
        }
        return res;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};