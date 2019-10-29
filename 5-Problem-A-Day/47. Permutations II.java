class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> ans = new LinkedList<>();
        int[] used = new int[nums.length];
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i++)
            used[i] = 0;
        backtrack(nums, new LinkedList<>(), used, ans);
        return ans;
    }

    private void backtrack(int[] nums, List<Integer> curr, int[] used, List<List<Integer>> ans) {
        if (curr.size() == nums.length)
            ans.add(new LinkedList<>(curr));
        else {
            for (int i = 0; i < nums.length; i++) {
                if (used[i] == 1 || i != 0 && nums[i] == nums[i - 1] && used[i - 1] == 0)
                    continue;
                used[i] = 1;
                curr.add(nums[i]);
                backtrack(nums, curr, used, ans);
                used[i] = 0;
                curr.remove(curr.size() - 1);
            }
        }
    }
}
