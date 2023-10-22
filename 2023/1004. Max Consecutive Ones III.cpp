class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0, start = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (k < 0 && start < i) {
                if (nums[start] == 0) {
                    k++;
                }
                start++;
            }
            if(nums[i] == 0) {
                k--;
            }
            if (nums[i] == 1 || k >= 0) {
                res = max(res, i - start + 1);
            }
        }
        return res;
    }
};