class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<int> rightMaxes(nums.size()), leftMaxes(nums.size()), rightMins(nums.size());
        int currMax = 0, currMin = INT_MAX;
        for (int i = (int)nums.size() - 2; i >= 0; i--) {
            currMax = max(currMax, nums[i + 1]);
            currMin = min(currMin, nums[i + 1]);
            rightMaxes[i] = currMax;
            rightMins[i] = currMin;
        }
        currMax = 0;
        for (int i = 1; i < nums.size(); i++) {
            currMax = max(currMax, nums[i - 1]);
            leftMaxes[i] = currMax;
        }
        long long res = INT_MIN;
        for (int i = 1; i < nums.size(); i++) {
            res = max(res, max((long long)(leftMaxes[i] - nums[i]) * rightMaxes[i], (long long)(leftMaxes[i] - nums[i]) * rightMins[i]));
        }
        return res;
    }
};

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long res = 0;
        int maxValue = 0, maxDiff = 0;
        for (int n : nums) {
            res = max(res, 1LL * maxDiff * n);
            maxDiff = max(maxDiff, maxValue - n);
            maxValue = max(maxValue, n);
        }
        return res;
    }
};