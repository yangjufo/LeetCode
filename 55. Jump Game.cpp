class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty())
            return false;
        int now_step =  nums.size() - 1;
        for(int i = nums.size() - 1; i > -1; i--){
            if(nums[i] >= now_step - i)
                now_step = i;
        }
        return now_step == 0;        
    }
};