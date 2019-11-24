class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> ans = new LinkedList<>();
        if (k > 9 || n > 55)
            return ans;
        backtrack(k, n, 1, new LinkedList<>(), ans);
        return ans;
    }

    private void backtrack(int k, int n, int start, List<Integer> curr, List<List<Integer>> ans) {
        if (curr.size() == k && n == 0)
            ans.add(new LinkedList<>(curr));
        else if (curr.size() < k && n > 0) {
            for (int i = start; i < 10; i++) {
                curr.add(i);
                backtrack(k, n - i, i + 1, curr, ans);
                curr.remove(curr.size() - 1);
            }
        }
    }
}
