class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) return true;
        int curr = 0;
        for (int i = 0; i < nums.size() && i <= curr && curr < nums.size() - 1; i++) {
            curr = max(i + nums[i], curr);
        }
        return curr >= nums.size() - 1;
    }
};

