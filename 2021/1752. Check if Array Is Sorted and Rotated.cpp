class Solution {
public:
    bool check(vector<int>& nums) {
        int drop = 0, i = 0;
        
        for (int i = 0; i < nums.size() - 1 && drop < 2; i++) {
            if (nums[i] > nums[i + 1]) {
                drop += 1;
            }            
        }        
        
        return nums.empty() ? true : drop == 0 || (drop == 1 && nums.back() <= nums[0]);
                
    }
};