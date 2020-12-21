class Solution {
public:
    int directions[4][2] ={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = m == 0 ? 0 : matrix[0].size();
        vector<vector<int>> ans;        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            bfs(matrix, m, n, i, 0, pacific);
            bfs(matrix, m, n, i, n - 1, atlantic);
        }
        
        for (int j = 0; j < n; j++) {
            bfs(matrix, m, n, 0, j, pacific);
            bfs(matrix, m, n, m - 1, j, atlantic);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        
        return ans;
    }
    
    void bfs(vector<vector<int>>& matrix, int m, int n, int x, int y, vector<vector<bool>>& visited) {
        if (visited[x][y]) return;
        queue<int*> nodes;
        nodes.push(new int[2]{x, y});
        while (!nodes.empty()) {
            int* curr = nodes.front();
            nodes.pop();
            visited[curr[0]][curr[1]] = true;
            for (int* dir : directions) {
                int a = curr[0] + dir[0], b = curr[1] + dir[1];
                if (a < 0 || a >= m || b < 0 || b >= n || visited[a][b] || matrix[a][b] < matrix[x][y])
                    continue;
                bfs(matrix, m, n, a, b, visited);
            }
        }        
    }
};