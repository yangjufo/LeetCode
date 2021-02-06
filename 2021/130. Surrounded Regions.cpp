class Solution {
public:
    int directions[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = (m == 0) ? 0 : board[0].size();
        if (m == 0 || n == 0) return;
        
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0, m, n);
            }
            if (board[i][n - 1] == 'O') {
                dfs(board, i, n - 1, m, n);
            }            
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                dfs(board, 0, j, m, n);
            }            
            if (board[m - 1][j] == 'O') {
                dfs(board, m - 1, j, m, n);
            }            
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = (board[i][j] == 'P') ? 'O' : 'X';
            }
        }        
    }
    
    void dfs(vector<vector<char>>& board, int row, int col, int m, int n) {
        board[row][col] = 'P';

        for (int i = 0; i < 4; i++) {
            int newRow = row + directions[i][0];
            int newCol = col + directions[i][1];

            if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || board[newRow][newCol] != 'O') {
                continue;
            }                                
            dfs(board, newRow, newCol, m, n);
        }        
    }
};