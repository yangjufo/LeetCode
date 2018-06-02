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
        int tmp;
        for(int i = 2; i < nums.size() - 1; i++){
            tmp = res[i - 2] + nums[i];
            res[i] = tmp > res[i - 1] ? tmp : res[i - 1];
        }
        int max = res[nums.size() - 2];
        res[0] = nums[1];
        res[1] = nums[2] > nums[1] ? nums[2] : nums[1];
        for(int i = 2; i < nums.size() - 1; i++){
            tmp = res[i - 2] + nums[i+1];
            res[i] = tmp > res[i - 1] ? tmp : res[i - 1];
        }
        return max > res[nums.size() - 2] ? max : res[nums.size() - 2];
    }
};