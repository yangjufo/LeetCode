class Solution {
    public boolean isValidSudoku(char[][] board) {
        int m = board.length, n = board[0].length;
        for (int r = 0; r < m; r++) {
            if (!validate(board, r, 0, r, n - 1))
                return false;
        }
        for (int c = 0; c < n; c++) {
            if (!validate(board, 0, c, m - 1, c))
                return false;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (!validate(board, i * 3, j * 3, i * 3 + 2, j * 3 + 2))
                    return false;
            }
        }
        return true;
    }

    private boolean validate(char[][] board, int r1, int c1, int r2, int c2) {
        // System.out.printf("%d, %d, %d, %d\n", r1, c1, r2, c2);
        Set<Character> nums = new HashSet<>();
        for (int r = r1; r <= r2; r++) {
            for (int c = c1; c <= c2; c++) {
                if (board[r][c] == '.')
                    continue;
                if (nums.contains(board[r][c]))
                    return false;
                nums.add(board[r][c]);
            }
        }
        return true;
    }
}
