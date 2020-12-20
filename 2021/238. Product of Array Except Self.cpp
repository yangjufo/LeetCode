class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        vector<int> res(nums.size());
        
        res[0] = 1;
        for (int i = 1; i < nums.size(); i++) {            
            res[i] = res[i - 1] * nums[i - 1];            
        }        
        
        int right = 1; 
        for (int i = nums.size() - 1; i > -1; i--) {
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }
};