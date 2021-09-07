class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        vector<vector<int>> res;
        bool stale = false;
        while (!stale) {
            res = board;
            stale = true;            
            for (int i = 0; i < board.size(); i++) {
                int colCount = 0, currVal = -1;
                for (int j = 0; j < board[0].size(); j++) {                   
                    if (board[i][j] == 0 || board[i][j] != currVal) {
                        colCount = 0;
                        currVal = board[i][j];
                    }
                    colCount++;
                    if (colCount >= 3) {
                        res[i][j] = res[i][j - 1] = res[i][j - 2] = -1;
                        stale = false;
                    }                    
                }
            }       
            for (int j = 0; j < board[0].size(); j++) {
                int rowCount = 0, currVal = -1;
                for (int i = 0; i < board.size(); i++) {                   
                    if (board[i][j] == 0 || board[i][j] != currVal) {
                        rowCount = 0;
                        currVal = board[i][j];
                    }
                    rowCount++;
                    if (rowCount >= 3) {
                        res[i][j] = res[i - 1][j] = res[i - 2][j] = -1;
                        stale = false;
                    }                    
                }
            }       
            
            for (int j = 0; j < board[0].size(); j++) {                   
                int index = (int)board.size() - 1;
                for (int i = (int)board.size() - 1; i >= 0; i--) {
                    if (res[i][j] != -1) {
                        board[index][j] = board[i][j];
                        index--;
                    }
                }
                while (index >= 0) {
                    board[index][j] = 0;
                    index--;
                }
            }
        }    
        return board;
    }
};