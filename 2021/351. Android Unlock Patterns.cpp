class Solution {
public:
    int total = 0;
    int numberOfPatterns(int m, int n) {
        vector<vector<bool>> visited(3, vector<bool>(3, false));
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                visited[row][col] = true;
                backtrack(m, n, visited, row, col, 1);
                visited[row][col] = false;
            }
        }        
        return total;
    }
    
    void backtrack(int m, int n, vector<vector<bool>>& visited, int row, int col, int count) {          
        if (count >= m && count <= n) total++;
        if (count >= n) return;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if ((i == row && j == col) || visited[i][j]
                    || ((i + row) % 2 == 0 && (j + col) % 2 == 0 && !visited[(i + row) / 2][(j + col) / 2])
                   ) continue;
                visited[i][j] = true;
                backtrack(m, n, visited, i, j, count + 1);
                visited[i][j] = false;
            }
        }
    }        
};