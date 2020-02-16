class Solution {
    public int maxSubArrayLen(int[] nums, int k) {
        int ans = 0;
        Map<Integer, Integer> sumMap = new HashMap<>();
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            if (sum == k)
                ans = i + 1;
            else if (sumMap.containsKey(sum - k))
                ans = Math.max(ans, i - sumMap.get(sum - k));
            if (!sumMap.containsKey(sum))
                sumMap.put(sum, i);
        }
        return ans;
    }
}
