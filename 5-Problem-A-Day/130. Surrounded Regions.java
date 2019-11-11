class Solution {
    private void check(char[][] board, int i, int j, int row, int col) {
        if (board[i][j] == 'O') {
            board[i][j] = '1';
            if (i > 1)
                check(board, i - 1, j, row, col);
            if (j > 1)
                check(board, i, j - 1, row, col);
            if (i + 1 < row)
                check(board, i + 1, j, row, col);
            if (j + 1 < col)
                check(board, i, j + 1, row, col);
        }
    }

    public void solve(char[][] board) {
        int row = board.length, col = row == 0 ? 0 : board[0].length;
        if (row == 0 || col == 0)
            return;

        for (int i = 0; i < row; i++) {
            check(board, i, 0, row, col);
            if (col > 1)
                check(board, i, col - 1, row, col);
        }

        for (int j = 1; j < col - 1; j++) {
            check(board, 0, j, row, col);
            if (row > 1)
                check(board, row - 1, j, row, col);
        }

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                board[i][j] = board[i][j] == 'O' ? 'X' : board[i][j];

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                board[i][j] = board[i][j] == '1' ? 'O' : board[i][j];

    }
}
