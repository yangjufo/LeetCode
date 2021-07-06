class Solution {
public:
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size(), n = image[0].size();
        int tX = m - 1, tY = n - 1, bX = 0, bY = 0;        
        queue<pair<int, int>> queue;
        queue.push({x, y});
        image[x][y] = 0;
        while (!queue.empty()) {
            int row = queue.front().first, col = queue.front().second;
            queue.pop();            
            tX = min(tX, row);
            tY = min(tY, col);
            bX = max(bX, row);
            bY = max(bY, col);
            for (int i = 0; i < 4; i++) {
                int newRow = row + directions[i][0], newCol = col + directions[i][1];
                if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || image[newRow][newCol] == '0') {
                    continue;
                }
                queue.push({newRow, newCol});
                image[newRow][newCol] = '0';
            }
        }
        return (bY - tY + 1) * (bX - tX + 1);
    }
};