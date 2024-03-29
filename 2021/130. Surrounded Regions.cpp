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

class Solution {
public:
    int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                dfs(board, 0, i);
            }
            if (m > 1 && board[m - 1][i] == 'O') {
                dfs(board, m - 1, i);
            }
        }
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if (n > 1 && board[i][n - 1] == 'O') {
                dfs(board, i, n - 1);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'Y') {
                    board[i][j] = 'O';
                }
            }
        }        
    }
    
    void dfs(vector<vector<char>>& board, int row, int col) {
        board[row][col] = 'Y';
        for (int i = 0; i < 4; i++) {
            int newRow = row + directions[i][0], newCol = col + directions[i][1]; // new position after move
            if (newRow < 0 || newRow >= board.size() || newCol < 0 || newCol >= board[0].size() || board[newRow][newCol] != 'O') {
                continue;
            }
            dfs(board, newRow, newCol);
        }
    }
};

class Solution {
public:
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            if (board[i][0] == 'O') {
                board[i][0] = 'Y';
                dfs(board, i, 0);
            }            
            if (board[i][board[0].size() - 1] == 'O') {
                board[i][board[0].size() - 1] = 'Y';
                dfs(board, i, board[0].size() - 1);
            }
        }
        for (int j = 0; j < board[0].size(); j++) {
            if (board[0][j] == 'O') {
                board[0][j] = 'Y';
                dfs(board, 0, j);
            }
            if (board[board.size() - 1][j] == 'O') {
                board[board.size() - 1][j] = 'Y';
                dfs(board, board.size() - 1, j);
            }
        }        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'Y') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }        
    }
    
    void dfs(vector<vector<char>>& board, int row, int col) {  
        for (int i = 0; i < 4; i++) {
            int newRow = row + directions[i][0], newCol = col + directions[i][1];
            if (newRow < 0 || newRow >= board.size() || newCol < 0 || newCol >= board[0].size() || board[newRow][newCol] != 'O') {
                continue;
            }
            board[newRow][newCol] = 'Y';
            dfs(board, newRow, newCol);
        }
    }
};