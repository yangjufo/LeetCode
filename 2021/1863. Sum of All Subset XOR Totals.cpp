class Solution {
public:
    int sum = 0;
    int subsetXORSum(vector<int>& nums) {
        backtrack(nums, 0, 0, false);        
        return sum;
    }
    
    void backtrack(vector<int>& nums, int start, int curr, bool empty) {        
        if (start >= nums.size()) {
            sum += curr;
            return;
        }
        backtrack(nums, start + 1, curr, empty);
        backtrack(nums, start + 1, (empty ? nums[start] : curr ^ nums[start]), false);
    }
};