class Solution {
public:
    int h[4] = {0, 0, 1, -1};
    int v[4] = {1, -1, 0, 0};
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0, count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {                
                if (grid[i][j] == 1) {
                    count = 1;
                    dfs(grid, i, j, count, maxArea);
                }
            }
        }
        return maxArea;
    }
    
    void dfs(vector<vector<int>>& grid, int row, int col, int& count, int& maxArea) {
        grid[row][col] = 0;
        maxArea = max(maxArea, count);
        
        for (int i = 0; i < 4; i++) {
            int newRow = row + h[i], newCol = col + v[i];
            if (newRow < 0 || newRow >= grid.size() || newCol < 0 || newCol >= grid[0].size() || grid[newRow][newCol] == 0) continue;
            count++;
            dfs(grid, newRow, newCol, count, maxArea);
        }
    }
};