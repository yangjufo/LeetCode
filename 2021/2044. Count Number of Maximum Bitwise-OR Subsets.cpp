class Solution {
public:
    int maxVal = 0, count = 0;
    int countMaxOrSubsets(vector<int>& nums) {        
        backtrack(nums, 0, 0);
        return count;
    }
    
    void backtrack(vector<int>& nums, int start, int curr) {        
        if (curr > maxVal) {
            count = 1;
            maxVal = curr;
        } else if (curr == maxVal) {
            count++;
        }
        for (int i = start; i < nums.size(); i++) {            
            backtrack(nums, i + 1, curr | nums[i]);            
        }
    }
};