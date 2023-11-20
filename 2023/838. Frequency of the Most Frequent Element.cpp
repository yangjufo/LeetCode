class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long sum = 0;
        int maxFreq = 0, start = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum + k < (long)(i - start + 1) * nums[i]) {
                sum -= nums[start];
                start++;
            }
            maxFreq = max(maxFreq, i - start + 1);
        }
        return maxFreq;
    }
};