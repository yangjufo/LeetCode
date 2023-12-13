class Solution {
public:
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void solve(vector<vector<char>>& board) {
        char visited = 'v';
        for (int i = 0; i < board.size(); i++) {
            if (board[i][0] == 'O') {
                bfs(board, i, 0, visited);
            }
            if (board[i][board[0].size() - 1] == 'O') {
                bfs(board, i, board[0].size() - 1, visited);
            }
        }
        for (int j = 0; j < board[0].size(); j++) {
            if (board[0][j] == 'O') {
                bfs(board, 0, j, visited);
            }
            if (board[board.size() - 1][j] == 'O') {
                bfs(board, board.size() - 1, j, visited);
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == visited) {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

    }

    void bfs(vector<vector<char>>& board, int row, int col, char visited) {
        queue<array<int, 2>> queue;
        board[row][col] = visited;
        queue.push({row, col});
        while (!queue.empty()) {
            int r = queue.front()[0], c = queue.front()[1];
            queue.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + dirs[i][0], nc = c + dirs[i][1];
                if (nr < 0 || nr >= board.size() || nc < 0 || nc >= board[0].size() || board[nr][nc] != 'O') {
                    continue;
                }
                board[nr][nc] = visited;
                queue.push({nr, nc});
            }
        }
    }
};