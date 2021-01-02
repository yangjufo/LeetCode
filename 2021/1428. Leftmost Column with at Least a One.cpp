/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimensions = binaryMatrix.dimensions();
        int m = dimensions[0], n = dimensions[1];
        if (m == 0 || n == 0) return -1;
        int minLeft = n;
        for (int i = 0; i < m; i++) {            
            minLeft = min(minLeft, binarySearch(binaryMatrix, i, n));            
        }
        return minLeft == n ? -1 : minLeft;
    }       
    int binarySearch(BinaryMatrix &binaryMatrix, int row, int n) {
        if (binaryMatrix.get(row, n - 1) == 0) return n;
        
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (binaryMatrix.get(row, mid) == 0) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
};

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimen = binaryMatrix.dimensions();
        int m = dimen[0], n = dimen[1];
        if (m == 0 || n == 0) return -1;
        int i = 0, j = n - 1, minLeft = -1;    
        while (i < m && j >= 0) {
            if (binaryMatrix.get(i, j) == 1) {
                minLeft = j;
                j--;                                
            } else {
                i++;
            }
        }
        return minLeft;
    }
};