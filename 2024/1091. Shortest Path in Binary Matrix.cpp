class Solution {
public:
    int dir[8][2] = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1},
                     {0, 1},  {1, 1},   {1, 0},  {1, -1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<array<int, 2>> queue;
        vector<vector<int>> mem(grid.size(),
                                vector<int>(grid[0].size(), INT_MAX));
        if (grid[0][0] == 1) {
            return -1;
        }
        queue.push({0, 0});
        mem[0][0] = 1;
        while (!queue.empty()) {
            int x = queue.front()[0], y = queue.front()[1];
            queue.pop();
            for (int i = 0; i < 8; i++) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if (nx < 0 || nx >= grid.size() || ny < 0 ||
                    ny >= grid[0].size() || grid[nx][ny] == 1 || mem[nx][ny] <= mem[x][y] + 1) {
                    continue;
                }
                mem[nx][ny] = mem[x][y] + 1;
                queue.push({nx, ny});
            }
        }
        return mem[grid.size() - 1][grid[0].size() - 1] == INT_MAX
                   ? -1
                   : mem[grid.size() - 1][grid[0].size() - 1];
    }
};