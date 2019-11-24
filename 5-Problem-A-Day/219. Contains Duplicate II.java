class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, Integer> idx = new HashMap<>();
        boolean ans = false;
        for (int i = 0; i < nums.length && !ans; i++) {
            if (idx.containsKey(nums[i]) && i - idx.get(nums[i]) <= k)
                ans = true;
            idx.put(nums[i], i);
        }
        return ans;
    }
}
