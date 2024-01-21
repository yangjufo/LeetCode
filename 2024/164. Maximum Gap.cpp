class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int exp = 1, maxVal = INT_MIN;
        for (int n : nums) {
            maxVal = max(maxVal, n);
        }
        while (maxVal / exp > 0) {
            vector<int> count(10, 0), output(nums.size());
            for (int n : nums) {
                count[(n / exp) % 10]++;
            }
            for (int i = 1; i < 10; i++) {
                count[i] += count[i - 1];
            }
            for (int i = nums.size() - 1; i >= 0; i--) {
                output[count[(nums[i] / exp) % 10] - 1] = nums[i];
                count[(nums[i] / exp) % 10] -= 1;
            }
            for (int i = 0; i < nums.size(); i++) {
                nums[i] = output[i];
            }

            exp *= 10;
        }
        int maxGap = 0;
        for (int i = 1; i < nums.size(); i++) {
            maxGap = max(maxGap, nums[i] - nums[i - 1]);
        }
        return maxGap;
    }
};