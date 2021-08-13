class Solution {
    int directions[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
public:    
    int islandPerimeter(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = -1;
                    return dfs(grid, i, j);
                }
            }
        }
        return 0;
    }
    
    int dfs(vector<vector<int>>& grid, int row, int col) {
        int curr = 0;
        for (int i = 0; i < 4; i++) {
            int newRow = row + directions[i][0], newCol = col + directions[i][1];
            if (newRow < 0 || newRow >= grid.size() || newCol < 0 || newCol >= grid[0].size()) {                
                curr += 1;
                continue;
            }
            if (grid[newRow][newCol] <= 0) {
                curr += grid[newRow][newCol] == 0 ? 1 : 0;
                continue;
            }
            grid[newRow][newCol] = -1;
            curr += dfs(grid, nQewRow, newCol);
        }
        return curr;
    }
};

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int sum = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) continue;
                if (i == 0 || grid[i - 1][j] == 0) {
                    sum++;
                }
                if (i + 1 == grid.size() || grid[i + 1][j] == 0) {
                    sum++;                    
                }
                if (j == 0 || grid[i][j - 1] == 0) {
                    sum++;
                }
                if (j + 1 == grid[0].size() || grid[i][j + 1] == 0) {
                    sum++;
                }
            }
        }
        return sum;
    }
};

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int sum = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) continue;
                sum += 4;
                if (i > 0 && grid[i - 1][j] == 1) {
                    sum -= 2;
                }                
                if (j >0 &&  grid[i][j - 1] == 1) {
                    sum -= 2;
                }
            }
        }
        return sum;
    }
};