class NumMatrix {

    int[][] preSum;
    int[][] matrix;

    public NumMatrix(int[][] matrix) {
        this.matrix = matrix;
        if (matrix.length != 0 && matrix[0].length != 0) {
            preSum = new int[matrix.length + 1][matrix[0].length + 1];
            for (int i = 1; i < matrix.length + 1; i++) {
                for (int j = 1; j < matrix[0].length + 1; j++) {
                    preSum[i][j] = matrix[i - 1][j - 1] + preSum[i][j - 1] + preSum[i - 1][j]
                            - preSum[i - 1][j - 1];
                }
            }
        }
    }

    public void update(int row, int col, int val) {
        matrix[row][col] = val;
        preSum = new int[matrix.length + 1][matrix[0].length + 1];
        for (int i = 1; i < matrix.length + 1; i++) {
            for (int j = 1; j < matrix[0].length + 1; j++) {
                preSum[i][j] = matrix[i - 1][j - 1] + preSum[i][j - 1] + preSum[i - 1][j]
                        - preSum[i - 1][j - 1];
            }
        }
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        return preSum[row2 + 1][col2 + 1] - preSum[row1][col2 + 1] - preSum[row2 + 1][col1]
                + preSum[row1][col1];
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such: NumMatrix obj = new
 * NumMatrix(matrix); obj.update(row,col,val); int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
