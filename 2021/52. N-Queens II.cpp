class Solution {
public:
    int count = 0;
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0, n);
        return count;
    }
    
    void backtrack(vector<string>& board, int row, int n) {        
        if (row >= n) {
            count++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (board[row][i] == '.' && canPlace(board, row, i, n)) {
                board[row][i] = 'Q';
                backtrack(board, row + 1, n);
                board[row][i] = '.';
            }
        }        
    }
    
    bool canPlace(vector<string>& board, int row, int col, int n) {        
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        
        for (int i = 0; i < row; i++) {
            if (row + col - i >= n || row + col - i < 0) continue;
            if (board[i][row + col - i] == 'Q') return false;
        }
        
        for (int i = 0; i < row; i++) {
            if (col + i - row >= n || col + i - row < 0) continue;
            if (board[i][col + i - row] == 'Q') return false;
        }
        
        return true;        
    }        
};