class Solution {
public:
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startRow = 0, startCol = 0, count= 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    startRow = i;
                    startCol = j;
                } else if (grid[i][j] == 0) {
                    count++;
                }
            }
        }                 
        return dfs(grid, startRow, startCol, count);
    }
    
    int dfs(vector<vector<int>>& grid, int row, int col, int count) {
        if (grid[row][col] == 2) {
            return count < 0 ? 1 : 0;
        } 
        int tmp = grid[row][col];
        grid[row][col] = -1;
        int pathCount = 0;
        for (int i = 0; i < 4; i++) {
            int newRow = row + directions[i][0], newCol = col + directions[i][1];            
            if (newRow < 0 || newRow >= grid.size() || newCol < 0 || newCol >= grid[0].size() || grid[newRow][newCol] == -1) {
                continue;
            }            
            pathCount += dfs(grid, newRow, newCol, count - 1);
        }
        grid[row][col] = tmp;
        return pathCount;
    }
};