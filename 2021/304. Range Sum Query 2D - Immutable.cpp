class NumMatrix {
public:
    vector<vector<int>> preSum;
    NumMatrix(vector<vector<int>>& matrix) {
        preSum.resize(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++) {            
            for (int j = 0; j < matrix[0].size(); j++) {
                preSum[i][j] = matrix[i][j];
                if (i > 0) {
                    preSum[i][j] += preSum[i - 1][j];
                }
                if (j > 0) {
                    preSum[i][j] += preSum[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    preSum[i][j] -= preSum[i - 1][j - 1];
                }         
            }            
        }        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = preSum[row2][col2];
        if (row1 > 0) {
            sum -= preSum[row1 - 1][col2];
        }
        if (col1 > 0) {
            sum -= preSum[row2][col1 - 1];
        }
        if (row1 > 0 && col1 > 0) {
            sum += preSum[row1 - 1][col1 - 1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */