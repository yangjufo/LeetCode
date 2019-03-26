class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < nums.length - 2; i++) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            twoSum(nums, i + 1, -nums[i], res);    
        }
        return res;
    }
    
    private void twoSum(int[] nums, int start, int target, List<List<Integer>> res) {
        int left = start, right = nums.length - 1;        
        while (left < right) {            
            if (nums[left] + nums[right] == target) {                
                res.add(new ArrayList<>(Arrays.asList(-target, nums[left], nums[right])));
                left += 1;
                right -= 1;
                while (left < right && nums[left] == nums[left - 1])
                    left += 1;
                while (left < right && nums[right] == nums[right + 1])
                    right -= 1;
            } 
            else if (nums[left] + nums[right] > target)
                right -= 1;
            else
                left += 1;
        }        
    }
}