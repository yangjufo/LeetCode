class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = m == 0 ? 0 : matrix[0].length;
        if (m * n == 0)
            return false;
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int tmp = matrix[mid / n][mid % n];
            if (tmp == target)
                return true;
            if (tmp < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
}
