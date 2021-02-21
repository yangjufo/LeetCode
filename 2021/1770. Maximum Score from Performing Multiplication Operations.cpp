class Solution {
public:    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        vector<vector<int>> mem(1001, vector<int>(1001, 0));
        return dfs(nums, multipliers, 0, 0, mem);
    }
    
    int dfs(vector<int>& nums, vector<int>& multipliers, int left, int start, vector<vector<int>>& mem) {        
        if (start >= multipliers.size()) {
            return 0;
        }
        if (!mem[left][start]) {
            int right = nums.size() - 1 - (start - left);
            mem[left][start] = max(nums[left] * multipliers[start] + dfs(nums, multipliers, left + 1, start + 1, mem), nums[right] * multipliers[start] + dfs(nums, multipliers, left, start + 1, mem));
        }
        return mem[left][start];
    }
};