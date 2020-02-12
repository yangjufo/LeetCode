class Solution {
    public int countComponents(int n, int[][] edges) {
        int[] roots = new int[n];
        for (int i = 0; i < n; i++)
            roots[i] = i;

        for (int[] e : edges) {
            int left = find(roots, e[0]);
            int right = find(roots, e[1]);
            if (left != right) {
                roots[left] = right;
                n--;
            }
        }
        return n;
    }

    private int find(int[] roots, int id) {
        while (roots[id] != id) {
            roots[id] = roots[roots[id]];
            id = roots[id];
        }
        return id;
    }
}
