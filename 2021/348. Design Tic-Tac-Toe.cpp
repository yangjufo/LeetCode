class TicTacToe {
public:
    vector<vector<int>> board;
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        board.resize(n, vector<int>(n, 0));
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        board[row][col] = player;        
        int i = 0;
        while (i < board.size() && board[i][col] == player) {
            i++;
        }
        if (i == board.size()) return player;
        
        i = 0;
        while (i < board[0].size() && board[row][i] == player) {
            i++;
        }
        if (i == board[0].size()) return player;
        
        if (row == col) {
            i = 0;
            while (i < board[0].size() && board[i][i] == player) {
                i++;
            }
            if (i == board[0].size()) return player;
        }
        
        if (row + col == board.size() - 1) {
            i = 0;
            while (i < board[0].size() && board[i][board[0].size() - 1 - i] == player) {
                i++;
            }
            if (i == board[0].size()) return player;
        }
        return 0;
        
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

class TicTacToe {
public:
    int n;
    vector<vector<int>> board;
    vector<vector<vector<int>>> playerTotal;
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        this->n = n;
        board.resize(n, vector<int>(n, 0));        
        playerTotal.resize(3, vector<vector<int>>(3, vector<int>(n, 0)));
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        board[row][col] = player;
        playerTotal[player][0][row]++;
        playerTotal[player][1][col]++;
        if (row == col) {
            playerTotal[player][2][0]++;
        }        
        if (row + col == n - 1) {
            playerTotal[player][2][1]++;
        }        
        if (playerTotal[player][0][row] == n || playerTotal[player][1][col] == n || playerTotal[player][2][0] == n || playerTotal[player][2][1] == n) {
            return player;
        }                
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */