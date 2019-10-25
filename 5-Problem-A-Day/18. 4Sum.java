class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        int right = nums.length - 1;
        List<List<Integer>> ans = new ArrayList<>();
        while (right > 2) {
            int left = 0;
            while (left < right - 2) {
                int i = left + 1, j = right - 1;
                while (i < j) {
                    int sum = nums[left] + nums[right] + nums[i] + nums[j];
                    if (sum < target)
                        i += 1;
                    else if (sum > target)
                        j -= 1;
                    else {
                        ans.add(Arrays.asList(nums[left], nums[i], nums[j], nums[right]));
                        while (i < j && nums[i] == nums[i + 1])
                            i += 1;
                        while (i < j && nums[j] == nums[j - 1])
                            j -= 1;
                        i += 1;
                        j -= 1;
                    }
                }
                while (left < right - 2 && nums[left] == nums[left + 1])
                    left += 1;
                left += 1;
            }
            while (right > 2 && nums[right] == nums[right - 1])
                right -= 1;
            right -= 1;
        }
        return ans;
    }
}
