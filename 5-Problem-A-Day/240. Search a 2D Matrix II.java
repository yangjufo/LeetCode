class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = m == 0 ? 0 : matrix[0].length;
        if (m * n == 0)
            return false;
        int row = 0, col = n - 1;
        while (row < m && col > -1) {
            if (matrix[row][col] > target)
                col -= 1;
            else if (matrix[row][col] < target)
                row += 1;
            else
                return true;
        }
        return false;
    }
}
