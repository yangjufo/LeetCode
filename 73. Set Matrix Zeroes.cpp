class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return;
        int zero_cols[matrix[0].size()] = {0};
        int zero_rows[matrix.size()] = {0};
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (matrix[i][j] == 0){
                    zero_rows[i] = 1;
                    zero_cols[j] = 1;
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++){
            if (zero_rows[i] != 1)
                continue;
            for (int j = 0; j < matrix[0].size(); j++){
                matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < matrix[0].size(); i++){
            if (zero_cols[i] != 1)
                continue;
            for (int j = 0; j < matrix.size(); j++){
                matrix[j][i] = 0;
            }
        }
    }
};