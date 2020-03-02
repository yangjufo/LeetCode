class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> indexes = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (indexes.containsKey(target - nums[i]))
                return new int[] {indexes.get(target - nums[i]), i};
            indexes.put(nums[i], i);
        }
        return new int[2];
    }
}
