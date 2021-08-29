class Solution {
public:
    int directions[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> rottens;
        int count = 0, total = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    rottens.push({i, j});
                    count++;
                }
                if (grid[i][j] != 0) {
                    total++;
                }
            }
        }
        int time = 0;
        while (count < total && !rottens.empty()) {
            time++;
            int size = rottens.size();
            for (int i = 0; i < size; i++) {
                int row = rottens.front().first, col = rottens.front().second;
                rottens.pop();
                for (int j = 0; j < 4; j++) {                    
                    int newRow = row + directions[j][0], newCol = col + directions[j][1];
                    if (newRow < 0 || newRow >= grid.size() || newCol < 0 || newCol >= grid[0].size() || grid[newRow][newCol] != 1) {
                        continue;
                    }
                    count++;
                    grid[newRow][newCol] = 2;
                    rottens.push({newRow, newCol});
                }
            }
        }
        return count < total ? -1 : time; 
    }
};