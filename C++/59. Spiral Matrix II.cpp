class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        res.resize(n, vector<int>{});
        for (int i = 0; i < n; i++){
            res[i].resize(n, 0);
        }
        int count = 1;
        int j, k;
        for (int i = 0; i < (n + 1) / 2; i++){
            for (j = i; j < n - i; j++){
                res[i][j] = count++;
            }
            j = j - 1;
            for (k = i + 1; k < n - i; k++){
                res[k][j] = count++;
            }
            k = k - 1;
            for (j = j - 1; j > i - 1; j--){
                res[k][j] = count++;
            }
            j = j + 1;
            for (k = n - i - 2; k > i; k--){
                res[k][j] = count++;
            }                                    
        }
        return res;
    }
};