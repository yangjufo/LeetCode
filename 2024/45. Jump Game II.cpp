class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int curr = 0, last = 0, step = 1;
        for (int i = 0; i < nums.size() && last + 1 < nums.size(); i++) {
            if (i > curr) {
                step += 1;
                curr = last;
            }
            last = max(i + nums[i], last);
        }
        return step;
    }
};