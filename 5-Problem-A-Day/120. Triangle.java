class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int[] curr = new int[triangle.size()];
        Arrays.fill(curr, 0);
        for (int i = 0; i < triangle.size(); i++) {
            for (int j = i; j >= 0; j--) {
                if (j == 0)
                    curr[0] += triangle.get(i).get(0);
                else if (j == i)
                    curr[i] = curr[i - 1] + triangle.get(i).get(i);
                else
                    curr[j] = Math.min(curr[j - 1], curr[j]) + triangle.get(i).get(j);
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int c : curr) {
            if (c < ans)
                ans = c;
        }
        return ans;
    }
}
