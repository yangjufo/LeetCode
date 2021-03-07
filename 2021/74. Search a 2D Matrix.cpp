class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchMatrix(matrix, 0, 0, matrix.size() - 1, matrix[0].size() - 1, target);
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int startRow, int startCol, int endRow, int endCol, int target) {        
        if (startRow > endRow || startCol > endCol) return false;
        int midRow = startRow + (endRow - startRow) / 2;
        int midCol = startCol + (endCol - startCol) / 2;
        if (matrix[midRow][midCol] == target) return true;
        if (matrix[midRow][midCol] > target) {
            return searchMatrix(matrix, startRow, startCol, endRow, midCol - 1, target) || searchMatrix(matrix, startRow, midCol, midRow - 1, endCol, target);
        }
        return searchMatrix(matrix, startRow, midCol + 1, endRow, endCol, target)
            || searchMatrix(matrix, midRow + 1, startCol, endRow, midCol, target);
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midVal = matrix[mid / n][mid % n];
            if (midVal == target) return true;
            if (midVal > target) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
};