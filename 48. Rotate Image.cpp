class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return;
        int tmp;
        int m = matrix.size();        
        for(int i = 0; i < m / 2; i++){
            for (int j = i; j < m - i - 1; j++){                
                tmp = matrix[i][j];
                matrix[i][j] = matrix[m - 1 - j][i];
                matrix[m - 1 -j][i] = matrix[m - 1 - i][m - 1 - j];
                matrix[m - 1 - i][m - 1 - j] = matrix[j][m -1 -i];   
                matrix[j][m - 1 - i] = tmp;                
            }            
        }
    }
};
