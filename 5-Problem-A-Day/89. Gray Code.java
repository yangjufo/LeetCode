class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> ans = new LinkedList<>();
        if (n >= 0)
            ans.add(0);
        if (n >= 1)
            ans.add(1);
        for (int i = 2; i <= n; i++) {
            List<Integer> tmp = new LinkedList<>(ans);
            for (int j = ans.size() - 1; j > -1; j--) {
                tmp.add(ans.get(j) | (1 << (i - 1)));
            }
            ans = new LinkedList<>(tmp);
        }
        return ans;
    }
}
