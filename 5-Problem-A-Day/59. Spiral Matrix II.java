class Solution {
    public int[][] generateMatrix(int n) {
        int[][] matrix = new int[n][n];
        int start = 1;
        for (int i = 0; i <= (n - 1) / 2; i++) {
            start = fill(matrix, i, i, n - i - 1, n - i - 1, start);
        }
        return matrix;
    }

    private int fill(int[][] matrix, int r1, int c1, int r2, int c2, int start) {
        for (int c = c1; c <= c2; c++) {
            matrix[r1][c] = start;
            start += 1;
        }
        for (int r = r1 + 1; r <= r2; r++) {
            matrix[r][c2] = start;
            start += 1;
        }
        for (int c = c2 - 1; c >= c1; c--) {
            matrix[r2][c] = start;
            start += 1;
        }
        for (int r = r2 - 1; r >= r1 + 1; r--) {
            matrix[r][c1] = start;
            start += 1;
        }
        return start;
    }
}
