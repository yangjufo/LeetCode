class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty())
            return 0;
        int i = 0, j = nums.size() - 1;
        while(i <= j){
            if(nums[i] == val){
                while(nums[j] == val && j > i)
                    j--;                
                nums[i] = nums[j];                
                j--;                
            }
            i++;
        }        
        return j + 1;
    }
};