class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        for (int kc = 0; kc < k; kc++) {
            int tmp = grid[grid.size() - 1][grid[0].size() - 1];
            for (int i = grid.size() - 1; i >= 0; i--) {
                for (int j = grid[0].size() - 1; j >= 0; j--) {
                    if (j == 0) {
                        if (i == 0) {
                            grid[i][j] = tmp;
                        } else {
                            grid[i][j] = grid[i - 1].back();
                        }
                    } else {
                        grid[i][j] = grid[i][j - 1];
                    }
                }
            }
        }
        return grid;
    }
};