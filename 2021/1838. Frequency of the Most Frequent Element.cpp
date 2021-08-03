class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long sum = 0;
        int start = 0, maxFreq = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum + k < (long)nums[i] * (i - start + 1)) {
                sum -= nums[start];
                start++;
            }
            maxFreq = max(maxFreq, i - start + 1);
        }
        return maxFreq;
    }
};

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long sum = 0, start = 0, maxFreq = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum + k < (int)nums[i] * (i - start + 1)) {
                sum -= nums[start];
                start++;
            }
            maxFreq = max(maxFreq, i - start + 1);
        }
        return maxFreq;
    }
};