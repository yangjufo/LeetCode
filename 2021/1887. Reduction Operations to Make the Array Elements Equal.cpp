class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), start = n - 1, count = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] != nums[start]) {
                count += n - i - 1;
                start = i;
            }
        }
        return count;
    }
};