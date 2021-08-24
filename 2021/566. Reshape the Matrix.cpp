class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {        
        if (mat.size() * mat[0].size() != r * c) return mat;
        
        vector<vector<int>> res(r, vector<int>(c));
        int mr = 0, mc = 0;
        for (int i = 0; i < r; i++) {            
            for (int j = 0; j < c; j++) {                                
                res[i][j] = mat[mr][mc];
                if (mc + 1 >= mat[0].size()) {
                    mr++;
                    mc = 0;
                } else {
                    mc++;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if (m * n != r * c) return mat;
        vector<vector<int>> res(r, vector<int>(c, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {   
                res[(i * n + j) / c][(i * n + j) % c] = mat[i][j];
            }
        }
        return res;
    }
};