class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> numRead = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            if (numRead.contains(nums[i]))
                return true;
            numRead.add(nums[i]);
        }
        return false;
    }
}