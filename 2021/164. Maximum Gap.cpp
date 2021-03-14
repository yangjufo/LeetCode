class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int maxDiff = 0;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            maxDiff = max(maxDiff, nums[i] - nums[i - 1]);
        }
        return maxDiff;
    }
};

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() <= 1) return 0;        
        int minVal = nums[0], maxVal = nums[0];
        for (int n : nums) {
            minVal = min(n, minVal);
            maxVal = max(n, maxVal);
        }                
        
        int N = nums.size(), gap = (int)ceil((maxVal - minVal) * 1.0 / (N - 1));
        int bucketMin[N - 1], bucketMax[N - 1];
        fill(bucketMin, bucketMin + (N - 1), INT_MAX);
        fill(bucketMax, bucketMax + (N - 1), INT_MIN);
        for (int n : nums) {
            if (n == minVal || n == maxVal) continue;
            int index = (n - minVal) / gap;
            bucketMin[index] = min(bucketMin[index], n);
            bucketMax[index] = max(bucketMax[index], n);
        }
        
        int previous = minVal, maxDiff = 0;
        for (int i = 0; i < N - 1; i++) {
            if (bucketMin[i] == INT_MAX) continue;
            maxDiff = max(bucketMin[i] - previous, maxDiff);
            previous = bucketMax[i];
        }
        return max(maxDiff, maxVal - previous);
    }
};