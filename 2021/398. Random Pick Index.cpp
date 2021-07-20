class Solution {
public:
    unordered_map<int, vector<int>> indexes;
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            indexes[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        return indexes[target][rand() % indexes[target].size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */