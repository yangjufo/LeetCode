class Solution {
public:
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int islandPerimeter(vector<vector<int>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                dfs(grid, count, i, j);
            }
        }
        return count;
    }

    void dfs(vector<vector<int>>& grid, int& count, int r, int c) {
        if (r >= grid.size() || c >= grid[0].size() || r < 0 || c < 0 || grid[r][c] <= 0) {
            return;
        }
        grid[r][c] = -1;
        int sides = 0;
        for (int d = 0; d < 4; d++) {
            int x = r + dir[d][0], y = c + dir[d][1];
            if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) {
                sides++;
                continue;
            }
            dfs(grid, count, x, y);
        }
        count += sides;
    }
};