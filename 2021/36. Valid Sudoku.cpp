class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {        
        vector<vector<bool>> rows(9, vector<bool>(10, false));
        vector<vector<bool>> cols(9, vector<bool>(10, false));
        vector<vector<bool>> cells(9, vector<bool>(10, false));
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {    
                if (board[i][j] == '.') continue;
                int n = board[i][j] - '0';
                if (rows[i][n] || cols[j][n] || cells[i/3*3+j/3][n]) return false;
                rows[i][n] = true;
                cols[j][n] = true;
                cells[i/3*3+j/3][n] = true;
            }
        }
        
        return true;
    }
};