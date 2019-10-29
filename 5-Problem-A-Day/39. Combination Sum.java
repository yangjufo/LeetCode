class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> ans = new LinkedList<>();
        backtrack(candidates, 0, 0, target, new LinkedList<Integer>(), ans);
        return ans;
    }

    private void backtrack(int[] candidates, int start, int sum, int target, List<Integer> curr,
            List<List<Integer>> ans) {
        if (sum == target)
            ans.add(new LinkedList<Integer>(curr));
        else {
            for (int i = start; i < candidates.length; i++) {
                if (sum + candidates[i] <= target) {
                    curr.add(candidates[i]);
                    backtrack(candidates, i, sum + candidates[i], target, curr, ans);
                    curr.remove(curr.size() - 1);
                }
            }
        }
    }
}
