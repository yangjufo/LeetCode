class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int maxScore = nums[k], minVal = nums[k], i = k, j = k;
        while (i > 0 || j + 1< nums.size()) {
            if ((i > 0 ? nums[i - 1] : 0) < (j + 1 < nums.size() ? nums[j + 1] : 0)) {
                j++;
                minVal = min(minVal, nums[j]);                
            } else {
                i--;
                minVal = min(minVal, nums[i]);                
            }
            maxScore = max(maxScore, minVal * (j - i + 1));
        }
        return maxScore;
    }
};