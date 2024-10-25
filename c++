class TicTacToe {
public:
    vector<vector<int>> rows, cols;
    vector<int> left, right;
    int target;
    TicTacToe(int n) {
        target = n;
        rows.resize(2, vector<int>(n));
        cols.resize(2, vector<int>(n));
        left.resize(2);
        right.resize(2);
    }

    int move(int row, int col, int player) {
        rows[player - 1][row] += 1;
        if (rows[player - 1][row] >= target) {
            return player;
        }
        cols[player - 1][col] += 1;
        if (cols[player - 1][col] >= target) {
            return player;
        }
        if (row == col) {
            left[player - 1] += 1;
            if (left[player - 1] >= target) {
                return player;
            }
        }
        if (row + col == target - 1) {
            right[player - 1] += 1;
            if (right[player - 1] >= target) {
                return player;
            }
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */