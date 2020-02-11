class Solution {
    public int[][] multiply(int[][] A, int[][] B) {
        int m = A.length, n = A[0].length, nB = B[0].length;
        int[][] ans = new int[m][nB];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] != 0) {
                    for (int k = 0; k < nB; k++) {
                        ans[i][k] += A[i][j] * B[j][k];
                    }
                }
            }
        }

        return ans;
    }
}
