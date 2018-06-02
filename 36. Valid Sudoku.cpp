class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> check;        
        for (int i = 0; i < board.size(); i++){
            check.clear();
            check.resize(10, 0);                                    
            for (int j = 0; j < board[i].size(); j++){
                if (board[i][j] == '.')
                    continue;                
                if (check[board[i][j] - '0'] == 1){                                                            
                    return false;
                }
                else
                    check[board[i][j] - '0'] = 1;
            }
        }        
        for (int i = 0; i < board[0].size(); i++){
            check.clear();
            check.resize(10, 0);
            for (int j = 0; j < board.size(); j++){
                if (board[j][i] == '.')
                    continue;
                if (check[board[j][i] - '0'] == 1)
                    return false;
                else
                    check[board[j][i] - '0'] = 1;
            }
        }
        for (int i = 0; i < 9; i++){
            check.clear();
            check.resize(10, 0);
            for (int j = 0; j < 3; j++){                
                for (int k = 0; k < 3; k++){
                    if (board[i / 3 * 3 + j][i % 3 * 3 + k] == '.')
                        continue;
                    if (check[board[i / 3 * 3 + j][i % 3 * 3+ k] - '0'] == 1)
                        return false;
                    else
                        check[board[i / 3 * 3+ j][i % 3 * 3 + k] - '0'] = 1;
                }
            }
        }
        return true;
    }
};
