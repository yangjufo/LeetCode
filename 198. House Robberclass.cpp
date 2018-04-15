class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return nums[0];
        int res[nums.size()];        
        res[0] = nums[0];
        res[1] = nums[1] > nums[0] ? nums[1] : nums[0];
        for(int i = 2; i < nums.size(); i++){
            int tmp = res[i - 2] + nums[i];
            res[i] = tmp > res[i - 1] ? tmp : res[i - 1];            
        }
        return res[nums.size() - 1];
    }
};