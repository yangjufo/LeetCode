class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = vbs(matrix, target);
        if (start < 0) {
            return false;
        }
        auto iter = lower_bound(matrix[start].begin(), matrix[start].end(), target);
        return iter != matrix[start].end() && *iter == target;
    }

    int vbs(vector<vector<int>>& matrix, int target) {
        int low = 0, high = matrix.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (matrix[mid][0] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return matrix[low][0] > target ? low - 1 : low;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid / n][mid % n] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return matrix[left / n][left % n] == target;
    }
};