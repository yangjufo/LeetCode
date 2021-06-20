class Solution {
public:
    int directions[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        for (int i = 0; i < grid2.size(); i++) {
            for (int j = 0; j < grid2[0].size(); j++) {
                if (grid2[i][j] == 1) {
                    if (dfs(grid1, grid2, i, j)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
    
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int row, int col) {
        grid2[row][col] = 0;
        bool valid = (grid1[row][col] == 1);
        for (int i = 0; i < 4; i++) {
            int newRow = row + directions[i][0], newCol = col + directions[i][1];
            if (newRow < 0 || newRow >= grid2.size() || newCol < 0 || newCol >= grid2[0].size() || grid2[newRow][newCol] != 1) {
                continue;
            }            
            if (grid1[newRow][newCol] != 1) {
                valid = false;
            }
            valid &= dfs(grid1, grid2, newRow, newCol);
        }
        return valid;
    }
};