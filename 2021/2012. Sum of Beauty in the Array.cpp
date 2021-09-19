class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        vector<int> postMin(nums.size(), 0);
        int currMin = INT_MAX;
        for (int i = (int)nums.size() - 1; i >= 0; i--) {            
            postMin[i] = currMin;
            currMin = min(currMin, nums[i]);
        }    
        int sum = 0, currMax = nums[0];
        for (int i = 1; i + 1 < nums.size(); i++) {            
            if (nums[i] > currMax && nums[i] < postMin[i]) {
                sum += 2;
            } else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1]) {
                sum += 1;
            }
            currMax = max(currMax, nums[i]);
        }
        return sum;
    }
};