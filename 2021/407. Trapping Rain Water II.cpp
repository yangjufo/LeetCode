class Solution {
public:
    int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        auto comparator = [](array<int, 3>& left, array<int, 3>& right) {
            return left[2] > right[2];
        };
        priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(comparator)> pq(comparator);
        
        int m = heightMap.size(), n = heightMap[0].size(), res = 0, maxHeight = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            pq.push({i, 0, heightMap[i][0]});            
            pq.push({i, n - 1, heightMap[i][n - 1]});            
            visited[i][0] = visited[i][n - 1] = true;
        }
        for (int j = 0; j < n; j++) {
            pq.push({0, j, heightMap[0][j]});
            pq.push({m - 1, j, heightMap[m - 1][j]});
            visited[0][j] = visited[m - 1][j] = true;
        }
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            maxHeight = max(maxHeight, curr[2]);
            for (int i = 0; i < 4; i++) {
                int newRow = curr[0] + directions[i][0], newCol = curr[1] + directions[i][1];
                if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || visited[newRow][newCol]) {
                    continue;
                }
                visited[newRow][newCol] = true;
                res += max(0, maxHeight - heightMap[newRow][newCol]);
                pq.push({newRow, newCol, heightMap[newRow][newCol]});
            }
        }
        
        return res;
    }
};