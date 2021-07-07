class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        vector<array<int, 3>> val1, val2;
        for (int i = 0; i < mat1.size(); i++) {
            for (int j = 0; j < mat1[0].size(); j++) {
                if (mat1[i][j] != 0) {
                    val1.push_back({i, j, mat1[i][j]});
                }
            }
        }
        for (int i = 0; i < mat2.size(); i++) {
            for (int j = 0; j < mat2[0].size(); j++) {
                if (mat2[i][j] != 0) {
                    val2.push_back({i, j, mat2[i][j]});
                }
            }
        }
        vector<vector<int>> res(mat1.size(), vector<int>(mat2[0].size(), 0));
        for (array<int, 3>& v1 : val1) {
            for(array<int, 3>& v2 : val2) {
                if (v1[1] == v2[0]) {
                    res[v1[0]][v2[1]] += v1[2] * v2[2];
                }                
            }
        }
        return res;
    }
};