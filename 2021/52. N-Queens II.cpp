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

class Solution {
public:
    vector<bool> cols, diags, rdiags;
    int total = 0;
    int totalNQueens(int n) {        
        cols.resize(n, false);
        diags.resize(2 * n - 1, false);
        rdiags.resize(2 * n - 1, false);
        backtrack(0, n);
        return total;
    }
    
    void backtrack(int row, int n) {
        if (row >= n) {
            total += 1;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (cols[col] || diags[row + col] || rdiags[col - row + n - 1]) continue;
            cols[col] = true;
            diags[row + col] = true;
            rdiags[col - row + n - 1] = true;
            backtrack(row + 1, n);
            cols[col] = false;
            diags[row + col] = false;
            rdiags[col - row + n - 1] = false;
        }
    }
};