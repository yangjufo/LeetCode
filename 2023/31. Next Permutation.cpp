class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int smallIndex = nums.size() - 2;
        while (smallIndex >= 0 && nums[smallIndex] >= nums[smallIndex + 1]) {
            smallIndex--;
        }
        int swapIndex = nums.size() - 1;
        while (smallIndex >= 0 && swapIndex > smallIndex && nums[swapIndex] <= nums[smallIndex]) {
            swapIndex--;
        }
        if (smallIndex >= 0) {
            swap(nums[smallIndex], nums[swapIndex]);
        }
        sort(nums.begin() + smallIndex + 1, nums.end());
    }
};