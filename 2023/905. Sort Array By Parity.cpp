class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = (int) nums.size() - 1, i = 0;
        while (i < right) {
            if (nums[i] % 2 == 0) {
                swap(nums[left], nums[i]);
                i = left + 1;
                left++;
            } else {
                swap(nums[right], nums[i]);
                right--;
            }
        }
        return nums;
    }
};