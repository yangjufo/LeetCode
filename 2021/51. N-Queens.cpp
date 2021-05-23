class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0, n);
        return res;
    }
    
    void backtrack(vector<string>& board, int row, int n) {        
        if (row >= n) {
            res.push_back(board);
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
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> cols(n, false), diags(n * 2 - 1, false), rdiags(n * 2 - 1, false);
        vector<string> curr;
        backtrack(cols, diags, rdiags, 0, n, curr);
        return res;
    }
    
    void backtrack(vector<bool>& cols, vector<bool>& diags, vector<bool>& rdiags, int row, int n, vector<string>& curr) {
        if (row >= n) {
            res.push_back(curr);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (cols[i] || diags[row + i] || rdiags[i - row + n - 1]) continue;
            cols[i] = true;
            diags[row + i] = true;
            rdiags[i - row + n - 1] = true;
            curr.push_back(string(i, '.') + "Q" + string(n - i - 1, '.'));
            backtrack(cols, diags, rdiags, row + 1, n, curr);
            curr.pop_back();
            cols[i] = false;
            diags[row + i] = false;
            rdiags[i - row + n - 1] = false;
        }
    }
};