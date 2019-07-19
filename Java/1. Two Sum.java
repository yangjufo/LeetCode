class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> numIndex = new HashMap<>();
        int[] res = new int[2];
        for (int i = 0; i < nums.length; i++) {
            if (numIndex.containsKey(target - nums[i])) {
                res[0] = numIndex.get(target - nums[i]);
                res[1] = i;
                break;
            }
            numIndex.put(nums[i], i);
        }
        return res;
    }
}
