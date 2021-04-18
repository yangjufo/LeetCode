class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> sum(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i][j] = matrix[i][j];
                if (i == 0 && j != 0) {
                    sum[i][j] += sum[i][j - 1];
                } else if (i != 0 && j == 0) {
                    sum[i][j] += sum[i - 1][j];
                } else if (i != 0 && j != 0) {                    
                    sum[i][j] += sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
                }
            }
        }
                
        
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int i2 = i; i2 < m; i2++) {
                    for (int j2 = j; j2 < n; j2++) {
                        if (sum[i2][j2] - (i == 0 ? 0 : sum[i - 1][j2]) - (j == 0 ? 0 : sum[i2][j - 1]) + (i == 0 || j == 0 ? 0 : sum[i - 1][j - 1]) == target) {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int res = 0, m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                unordered_map<int, int> count = {{0, 1}};
                int curr = 0;
                for (int k = 0; k < m; k++) {
                    curr += matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);
                    if (count.find(curr - target) != count.end()) {
                        res += count[curr - target];
                    }
                    count[curr]++;
                }
            }
        }
        return res;
    }
};