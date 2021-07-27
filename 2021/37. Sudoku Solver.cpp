class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {      
        backtrack(board);
    }
    
    pair<int, int> findEmpty(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
    
    bool canPlace(vector<vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < board.size(); i++) {
            if (board[i][col] == num) return false;
        }
        
        for (int j = 0; j < board[row].size(); j++){
            if (board[row][j] == num) return false;
        }
        
        int startRow = row / 3 * 3, startCol = col / 3 * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == num) return false;
            }
        }
        return true;
    }
    
    bool backtrack(vector<vector<char>>& board) {
        auto rowCol = findEmpty(board);
        int row = rowCol.first, col = rowCol.second;
        if (row == -1 || col == -1) return true;
        for (int i = 1; i < 10; i++) {
            if (canPlace(board, row, col, i + '0')) {
                board[row][col] = i + '0';
                if (backtrack(board)) {
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }
};

class Solution {
public:    
    void solveSudoku(vector<vector<char>>& board) {        
        dfs(board);
    }
    
    bool dfs(vector<vector<char>>& board) {
        auto rowCol = findEmpty(board);
        int row = rowCol.first, col = rowCol.second;
        if (row == -1 && col == -1) return true;
        for (int i = 1; i <= 9; i++) {
            if (canPlace(board, row, col, i + '0')) {
                board[row][col] = i + '0';
                if(dfs(board)) {
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }
    
    pair<int, int> findEmpty(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
    
    bool canPlace(vector<vector<char>>& board, int row, int col, char val) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == val || board[i][col] == val) return false;
        }
        for (int i = (row / 3 * 3); i < (row / 3 * 3) + 3; i++) {
            for (int j = (col / 3 * 3); j < (col / 3 * 3) + 3; j++) {
                if (board[i][j] == val) return false;
            }
        }
        return true;
    }
};