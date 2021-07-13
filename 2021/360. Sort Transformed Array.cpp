class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res(nums.size(), 0);
        if (a == 0) {            
            if (b < 0) {
                reverse(nums.begin(), nums.end());
            }
            for (int i = 0; i < res.size(); i++) {
                res[i] = nums[i] * b + c;
            }
        } else {            
            int index = (a < 0) ? nums.size() - 1 : 0, step = (a < 0) ? -1 : 1;
            int midIndex = lower_bound(nums.begin(), nums.end(), -b / (2 * a)) - nums.begin();
            int i = midIndex - 1, j = midIndex;
            double midVal = (double)(-b) / (2 * a);            
            while (i >= 0 || j < nums.size()) {
                if (i < 0 || (j < nums.size() && nums[j] - midVal < midVal - nums[i])) {
                    res[index] = a * nums[j] * nums[j] + b * nums[j] + c;
                    j++;
                } else {
                    res[index] = a * nums[i] * nums[i] + b * nums[i] + c;
                    i--;
                }                
                index += step;
            }            
        }
        return res;
    }
};