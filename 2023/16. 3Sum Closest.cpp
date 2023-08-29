class Solution {
public:

    int twoSumClosest(vector<int>& nums, int start, int target) {
        int left = start, right = (int) nums.size() - 1;
        int closest = 1000000000;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (abs(sum - target) < abs(closest - target)) {
                closest= sum;
            }
            if (sum == target) {
                return target;
            } else if (sum > target) {
                right--;
            } else {
                left++;
            }
        }
        return closest;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        int ret = 10000000;
        sort(nums.begin(), nums.end());
        for (int i = 0; i + 2 < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                i++;
            }
            int two = twoSumClosest(nums, i + 1, target - nums[i]);
            if (abs(ret - target) > abs(two + nums[i] -target)) {
                ret = two + nums[i];
            }
        }
        return ret;
    }
};