class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = 0;
        for (int i = 0; i < nums.size() && i <= last && last + 1 < nums.size(); i++) {
            last = max(i + nums[i], last);
        }
        return last + 1 >= nums.size();
    }
};