class Solution {
public:
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            if (board[i][0] == 'O') {
                board[i][0] = 'W';
                dfs(board, i, 0);
            }
            if (board[i][board[0].size() - 1] == 'O') {
                board[i][board[0].size() - 1] = 'W';
                dfs(board, i, board[0].size() - 1);
            }
        }
        for (int j = 0; j < board[0].size(); j++) {
            if (board[0][j] == 'O') {
                board[0][j] = 'W';
                dfs(board, 0, j);
            }
            if (board[board.size() - 1][j] == 'O') {
                board[board.size() - 1][j] = 'W';
                dfs(board, board.size() - 1, j);
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == 'W') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int x, int y) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dirs[i][0], ny = y + dirs[i][1];
            if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || board[nx][ny] != 'O') {
                continue;
            }
            board[nx][ny] = 'W';
            dfs(board, nx, ny);
        }
    }
};