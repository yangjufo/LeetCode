class Solution {
public:
    int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, m + n));
        queue<pair<int, int>> posQueue;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    res[i][j] = 0;
                }
                posQueue.push({i, j});
            }
        }
        while (!posQueue.empty()) {
            int row = posQueue.front().first, col = posQueue.front().second;
            posQueue.pop();
            for (int i = 0; i < 4; i++) {
                int newRow = row + directions[i][0], newCol = col + directions[i][1];
                if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || res[row][col] + 1 >= res[newRow][newCol]) {
                    continue;
                }
                res[newRow][newCol] = res[row][col] + 1;
                posQueue.push({newRow, newCol});
            }
        }
        return res;
    }        
};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, m + n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    res[i][j] = 0;
                } else {
                    if (i > 0) {
                        res[i][j] = min(res[i][j], res[i - 1][j] + 1);
                    } 
                    if (j > 0) {
                        res[i][j] = min(res[i][j], res[i][j - 1] + 1);                        
                    }
                }
            }                
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i < m - 1) {
                    res[i][j] = min(res[i][j], res[i + 1][j] + 1);
                }
                if (j < n - 1) {
                    res[i][j] = min(res[i][j], res[i][j + 1] + 1);
                }
            }
        }
        return res;
    }
};