class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = 0;
        for (int i = 0; i < nums.size() && last + 1 < nums.size(); i++) {
            if (i > last) {
                return false;
            }
            last = max(i + nums[i], last);
        }
        return true;
    }
};