class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1; 
        int i = 0;
        while (i <= right) {            
            if (nums[i] == 0 && i > left) {
                swap(nums, i, left);
                left++;                
            } else if (nums[i] == 2) {
                swap(nums, i, right);
                right--;                
            } else {
                i++;
            }            
        }                
    }
    
    void swap(vector<int>& nums, int index1, int index2) {
        if(index1 == index2) return;
        
        int tmp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = tmp;
    }
};