class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int negCount = 0, res = 0, neg0Start = 0, neg1Start = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {                
                negCount++;
                if (negCount == 1) {
                    neg1Start = i + 1;
                }
            } else if (nums[i] == 0) {
                negCount = 0;
                neg0Start = i + 1;
            }
            if (negCount % 2 == 0) {
                res = max(res, i - neg0Start + 1);
            } else {
                res = max(res, i - neg1Start + 1);
            }
        }
        return res;
    }
};