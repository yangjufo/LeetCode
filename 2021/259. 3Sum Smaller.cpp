class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += twoSumSmaller(nums, i + 1, target - nums[i]);
        }
        return total;
    }
    
    int twoSumSmaller(vector<int>& nums, int start, int target) {
        int left = start, right = nums.size() - 1, count = 0;
        while (left < right) {
            if (nums[left] + nums[right] < target) {
                count += (right - left);
                left++;
            } else {
                right--;
            }
        }
        return count;
    }
};