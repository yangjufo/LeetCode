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

class Solution {
public:
    vector<vector<int>> mem;
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        mem.resize(m, vector<int>(m, INT_MAX));
        dfs(nums, multipliers, 0, 0);
        return mem[0][0];
    }
    
    int dfs(vector<int>& nums, vector<int>& multipliers, int left, int index) {
        if (index >= multipliers.size() || left >= nums.size() || left > index) {
            return 0;
        }
        if (mem[left][index] < INT_MAX) {
            return mem[left][index];
        }        
        mem[left][index] = max(nums[left] * multipliers[index] + dfs(nums, multipliers, left + 1, index + 1), nums[(int)nums.size() - 1 - (index - left)] * multipliers[index] + dfs(nums, multipliers, left, index + 1));
        return mem[left][index];
    }
    
};