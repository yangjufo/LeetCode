class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> matrix(n, vector<int>(n, 1)), up(n, vector<int>(n, 0)), down(n, vector<int>(n, 0)), left(n, vector<int>(n, 0)), right(n, vector<int>(n, 0));
        for (vector<int>& m : mines) {
            matrix[m[0]][m[1]] = 0;
        }        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    left[i][j] = j == 0 ? 1 : left[i][j - 1] + 1;
                }                
            }
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == 1) {
                    right[i][j] = j + 1 == n ? 1 : right[i][j + 1] + 1;
                }
            }
        }
        int maxLen = 0;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] == 1) {
                    up[i][j] = i == 0 ? 1 : up[i - 1][j] + 1;
                }
            }
            for (int i = n - 1; i >= 0; i--) {
                if (matrix[i][j] == 1) {
                    down[i][j] = i + 1 == n ? 1 : down[i + 1][j] + 1;
                }                
                maxLen = max(maxLen, min(min(left[i][j], right[i][j]), min(up[i][j], down[i][j])));
            }
        }
        return maxLen;
    }
};