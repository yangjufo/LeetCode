class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new LinkedList<>();
        List<Integer> numsList = new ArrayList<>();
        for (int num : nums)
            numsList.add(num);
        backtrack(nums.length, numsList, ans, 0);
        return ans;
    }

    private void backtrack(int n, List<Integer> nums, List<List<Integer>> ans, int first) {
        if (first == n)
            ans.add(new ArrayList<>(nums));
        else {
            for (int i = first; i < n; i++) {
                Collections.swap(nums, first, i);
                backtrack(n, nums, ans, first + 1);
                Collections.swap(nums, first, i);
            }
        }
    }
}
