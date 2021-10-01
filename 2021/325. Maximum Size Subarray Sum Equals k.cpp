class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> preSum;
        int sum = 0, maxLen = 0;
        preSum[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (preSum.find(sum - k) != preSum.end()) {
                maxLen = max(maxLen, i - preSum[sum - k]);
            }
            if (preSum.find(sum) == preSum.end()) {
                preSum[sum] = i;
            }
        }
        return maxLen;
    }
};

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> sumMap = {{0, -1}};
        int maxLen = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];            
            if (sumMap.find(sum - k) != sumMap.end()) {
                maxLen = max(maxLen, i - sumMap[sum - k]);
            }
            if (sumMap.find(sum) == sumMap.end()) {
                sumMap[sum] = i;
            }
        }
        return maxLen;
    }
};