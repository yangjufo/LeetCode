class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int step = 1, last = nums[0], reach = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (i > reach) {
                step++;
                reach = last;
            }
            last = max(i + nums[i], last);
        }
        return step;
    }
};