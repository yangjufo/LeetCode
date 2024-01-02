class Solution {
public:
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }
        return maxArea;
    }

    int dfs(vector<vector<int>>& grid, int row, int col) {
        int count = 1;
        grid[row][col] = -1;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                for (int d = 0; d < 4; d++) {
                    int nr = row + dirs[d][0], nc = col + dirs[d][1];
                    if (nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size() || grid[nr][nc] != 1) {
                        continue;
                    }
                    count += dfs(grid, nr, nc);
                }
            }
        }
        return count;
    }
};