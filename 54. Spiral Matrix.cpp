class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty())
            return res;
        int height = matrix.size();
        int width = matrix[0].size();
        int i, j, k;
        int level = (min(height, width) + 1) / 2;
        for (i = 0; i < level; i++){
            for (j = i; j < width - i; j++){
                res.push_back(matrix[i][j]);
            }
            j -= 1;
            for (k = i + 1; k < height - i; k++){
                res.push_back(matrix[k][j]);
            }
            k -= 1;
            j -= 1;
            for (; j > i && k > i; j--){
                res.push_back(matrix[k][j]);
            }
            for (; k > i && j == i; k--){
                res.push_back(matrix[k][j]);
            }
        }
        return res;
    }
};