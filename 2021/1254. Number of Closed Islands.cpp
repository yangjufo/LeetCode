class Solution {
public:
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    if(!dfs(grid, i, j)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
    
    bool dfs(vector<vector<int>>& grid, int row, int col) {
        bool border = (row <= 0 || row + 1 >= grid.size() || col <= 0 || col + 1 >= grid[0].size());
        grid[row][col] = 1;
        for (int i = 0; i < 4; i++) {
            int newRow = row + dir[i][0], newCol = col + dir[i][1];
            if (newRow < 0 || newRow >= grid.size() || newCol < 0 || newCol >= grid[0].size() || grid[newRow][newCol] == 1) {
                continue;
            }
            border |= dfs(grid, newRow, newCol);
        }
        return border;        
    }
    
};