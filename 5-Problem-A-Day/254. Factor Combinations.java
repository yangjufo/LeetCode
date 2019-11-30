class Solution {

    private void dfs(List<List<Integer>> ans, List<Integer> item, int n, int start) {
        if (n <= 1) {
            if (item.size() > 1)
                ans.add(new ArrayList<Integer>(item));
            return;
        }
        for (int i = start; i <= n; i++) {
            if (n % i == 0) {
                item.add(i);
                dfs(ans, item, n / i, i);
                item.remove(item.size() - 1);
            }
        }
    }

    public List<List<Integer>> getFactors(int n) {
        List<List<Integer>> ans = new ArrayList<>();
        dfs(ans, new ArrayList<Integer>(), n, 2);
        return ans;
    }
}
