class Solution {
    
    int winner(vector<int>& nums, int start, int end, vector<vector<int>>& memo) {
        if (start == end) {
            return nums[start];
        }
        if (memo[start][end] > -1) {
            return memo[start][end];            
        }
        int pickStart = nums[start] - winner(nums, start + 1, end, memo);
        int pickEnd = nums[end] - winner(nums, start, end - 1, memo);
        memo[start][end] = max(pickStart, pickEnd);
        return memo[start][end];
    }
    
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> memo(nums.size(), vector<int>(nums.size(), -1));
        return winner(nums, 0, (int)nums.size() - 1, memo) >= 0;
    }
    
    
};