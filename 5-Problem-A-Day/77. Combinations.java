class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> ans = new LinkedList<>();
        backtrack(n, 1, k, new LinkedList<>(), ans);
        return ans;
    }

    private void backtrack(int n, int start, int k, List<Integer> curr, List<List<Integer>> ans) {
        if (curr.size() == k)
            ans.add(new LinkedList<>(curr));
        else {
            for (int i = start; i <= n; i++) {
                curr.add(i);
                backtrack(n, i + 1, k, curr, ans);
                curr.remove(curr.size() - 1);
            }
        }
    }
}
