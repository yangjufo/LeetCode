class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        
        if (i >= 0) {            
            int j = nums.size() - 1;
            while (j > i && nums[j] <= nums[i]) {
                j--;
            }
            
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;                    
        } 
        reverse(nums.begin() + i + 1, nums.end());                
    }
};