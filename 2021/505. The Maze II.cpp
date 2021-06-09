class Solution {
public:
    int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dis(m, vector<int>(n, -1));        
        dis[start[0]][start[1]] = 0;
        queue<pair<int, int>> posQueue;
        posQueue.push({start[0], start[1]});
        while (!posQueue.empty()) {
            int row = posQueue.front().first, col = posQueue.front().second;
            posQueue.pop();
            for (int i = 0; i < 4; i++) {                
                auto newPos = roll(maze, row, col, directions[i][0], directions[i][1]);
                int newRow = newPos.first, newCol = newPos.second, newDis = dis[row][col] + abs(newRow - row) + abs(newCol - col);                
                if (dis[newRow][newCol] < 0 || dis[newRow][newCol] > newDis) {                    
                    dis[newRow][newCol] = newDis;
                    if (newRow != destination[0] || newCol != destination[1]) {                        
                        posQueue.push({newRow, newCol});
                    }                    
                }
            }
        }
        return dis[destination[0]][destination[1]];
    }
    
    pair<int, int> roll(vector<vector<int>>& maze, int row, int col, int hD, int vD) {        
        while (row >= 0 && row < maze.size() && col >= 0 && col < maze[0].size() && maze[row][col] != 1) {
            row += hD;
            col += vD;
        }
        return {row - hD, col - vD};
    }
};