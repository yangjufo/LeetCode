class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<bool>> matrix(n + 1, vector<bool>(n + 1, false));
        for (vector<int>& t : trust) {
            matrix[t[0]][t[1]] = true;
        }
        for (int i = 1; i <= n; i++) {
            bool valid = true;
            for (int j = 1; j <= n && valid; j++) {
                if (i == j) {
                    continue;
                }
                if (matrix[i][j] || !matrix[j][i]) {
                    valid = false;
                }
            }
            if (valid) {
                return i;
            }
        }
        return -1;
    }
};