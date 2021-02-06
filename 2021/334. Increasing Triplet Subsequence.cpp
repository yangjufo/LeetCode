class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int oneMin = INT_MAX, twoMin = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > twoMin) return true;
            
            if (nums[i] > oneMin) {
                twoMin = min(nums[i], twoMin);
            }
            oneMin = min(oneMin, nums[i]);            
        }
        return false;
    }
};