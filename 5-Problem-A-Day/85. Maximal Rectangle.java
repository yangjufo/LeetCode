class Solution {
    public int maximalRectangle(char[][] matrix) {
        int m = matrix.length, n = m == 0 ? 0 : matrix[0].length;
        if (m * n == 0)
            return 0;

        int[] left = new int[n], right = new int[n], height = new int[n];
        Arrays.fill(right, n);

        int ans = 0;
        for (int i = 0; i < m; i++) {
            int curLeft = 0, curRight = n;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    left[j] = Math.max(left[j], curLeft);
                else {
                    left[j] = 0;
                    curLeft = j + 1;
                }
            }
            for (int j = n - 1; j > -1; j--) {
                if (matrix[i][j] == '1')
                    right[j] = Math.min(right[j], curRight);
                else {
                    right[j] = n;
                    curRight = j;
                }
            }
            for (int j = 0; j < n; j++)
                ans = Math.max(ans, (right[j] - left[j]) * height[j]);
        }
        return ans;
    }
}
