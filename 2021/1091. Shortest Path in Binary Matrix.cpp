class Solution {
public:
    int directions[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();             
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return -1;
                   
        queue<pair<int, int>> queue;
        queue.push({0, 0});
        grid[0][0] = 1;
        while (!queue.empty()) {
            int row = queue.front().first, col = queue.front().second;
            queue.pop();
            int distance = grid[row][col];            
            if (row == m - 1 && col == n - 1){                    
                return distance;
            }                 
            for (pair<int, int> nei : getNeighbors(grid, row, col, m, n)) {
                queue.push(nei);
                grid[nei.first][nei.second] = distance + 1;
            }
        }
        return -1;        
    }
    
    vector<pair<int, int>> getNeighbors(vector<vector<int>>& grid, int row, int col, int m, int n) {
        vector<pair<int, int>> neighbors;
        for (int i = 0; i < 8; i++) {
            int newRow = row + directions[i][0], newCol = col + directions[i][1];
            if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || grid[newRow][newCol] != 0) continue;
            neighbors.push_back({newRow, newCol});
        }
        return neighbors;
    }
    
};

class Solution {
public:
    int directions[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();             
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return -1;
                   
        queue<pair<int, int>> queue;
        queue.push({0, 0});
        grid[0][0] = 1;
        int distance = 0;
        while (!queue.empty()) {            
            int size = queue.size();
            distance++;
            for (int s = 0; s < size; s++) {
                int row = queue.front().first, col = queue.front().second;            
                queue.pop();                
                if (row == m - 1 && col == n - 1){                    
                    return distance;
                }                 
                for (int i = 0; i < 8; i++) {
                    int newRow = row + directions[i][0], newCol = col + directions[i][1];
                    if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || grid[newRow][newCol] != 0) continue;
                    grid[newRow][newCol] = 1;
                    queue.push({newRow, newCol});
                }
            }            
        }
        return -1;        
    }
};

class Solution {
public:
    int directions[8][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {1, -1}, {1, 1}, {-1, 1}, {-1, -1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), dis = 0;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        if (grid[0][0] == 1) return -1;
        visited[0][0] = true;
        queue<pair<int, int>> cellQueue;
        cellQueue.push({0, 0});
        while (!cellQueue.empty()) {
            dis++;
            int size = cellQueue.size();
            while (size > 0) {
                int row = cellQueue.front().first, col = cellQueue.front().second;
                if (row == n - 1 && col == n - 1) {
                    return dis;
                }
                cellQueue.pop();
                size--;
                for (int i = 0; i < 8; i++) {
                    int newRow = row + directions[i][0], newCol = col + directions[i][1];
                    if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= n || grid[newRow][newCol] == 1 || visited[newRow][newCol]) {
                        continue;
                    }
                    visited[newRow][newCol] = true;
                    cellQueue.push({newRow, newCol});
                }
            }
        }
        return -1;
    }
};