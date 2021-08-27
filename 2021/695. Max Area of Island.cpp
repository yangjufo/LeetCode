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

class Solution {
public:
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
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
    
    int dfs(vector<vector<int>>& grid, int x, int y) {
        grid[x][y] = 0;
        int area = 1;
        for (int i = 0; i < 4; i++) {
            int newX = x + directions[i][0], newY = y + directions[i][1];
            if (newX < 0 || newX >= grid.size() || newY < 0 || newY >= grid[0].size() || grid[newX][newY] != 1) {
                continue;
            }
            area = max(area, area + dfs(grid, newX, newY));
        }
        return area;
    }
};

class Solution {
public:
    int directions[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }
        return maxArea;
    }
    
    int dfs(vector<vector<int>>& grid, int row, int col) {
        int curr = 1;
        for (int i = 0; i < 4; i++) {
            int newRow = row + directions[i][0], newCol = col + directions[i][1];
            if (newRow < 0 || newRow >= grid.size() || newCol < 0 || newCol >= grid[0].size() || grid[newRow][newCol] == 0) {
                continue;
            }
            grid[newRow][newCol] = 0;
            curr += dfs(grid, newRow, newCol);
        }
        return curr;
    }
};