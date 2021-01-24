class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dia(m + n - 1, vector<int>{});
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dia[m + j - i - 1].push_back(mat[i][j]);                
            }
        }
        for (int i = 0; i < m + n - 1; i++) {
            sort(dia[i].begin(), dia[i].end());
        } 
        vector<vector<int>> res(m, vector<int>(n, 0));
        vector<int> diaIndex(dia.size(), 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = dia[m + j - i - 1][diaIndex[m + j - i - 1]];
                diaIndex[m + j - i - 1]++;
            }
        }
        
        return res;
    }
};