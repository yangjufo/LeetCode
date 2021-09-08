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

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int prev1 = INT_MAX, prev2 = INT_MAX;
        for (int n : nums) {
            if (n > prev2) return true;
            if (n < prev1) prev1 = n;
            else if (n > prev1 && n < prev2) prev2 = n;
        }
        return false;
    }
};