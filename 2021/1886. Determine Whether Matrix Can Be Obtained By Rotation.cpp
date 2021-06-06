class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for (int i = 0; i < 4; i++) {
            mat = turn(mat, n);
            if (mat == target) return true;
        }
        return false;
    }    
    
    vector<vector<int>> turn(vector<vector<int>>& mat, int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[j][n - 1 - i] = mat[i][j];
            }
        }
        return res;
    }
};