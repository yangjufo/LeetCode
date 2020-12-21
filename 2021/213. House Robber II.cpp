class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];            
        
        return max(robOne(nums, 0, nums.size() - 2), robOne(nums, 1, nums.size() - 1));
    }
    
    int robOne(vector<int>& nums, int left, int right) {        
        int prev = 0, curr = 0;
        for (int i = left; i <= right; i++) {
            int tmp = max(nums[i] + prev, curr);
            prev = curr;
            curr = tmp;
        }
        return curr;
    }
};