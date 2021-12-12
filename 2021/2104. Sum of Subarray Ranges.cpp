class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {            
            int minVal = nums[i], maxVal = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                minVal = min(minVal, nums[j]);
                maxVal = max(maxVal, nums[j]);
                ans += maxVal - minVal;
            }                            
        }
        return ans;
    }
};