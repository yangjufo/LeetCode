class Solution {
public:
    int dirs[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    count += 1;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>& grid, int x, int y) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dirs[i][0], ny = y + dirs[i][1];
            if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size() ||
                grid[nx][ny] == '0') {
                continue;
            }
            grid[nx][ny] = '0';
            dfs(grid, nx, ny);
        }
    }
};