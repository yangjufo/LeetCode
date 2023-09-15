class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<long long> rows(9), cols(9), grids(9);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int n = board[i][j] - '0';
                if ((rows[i] & (1 << n)) > 0) return false;
                rows[i] |= (1 << n);
                if ((cols[j] & (1 << n)) > 0) return false;
                cols[j] |= (1 << n);
                int index = i / 3 * 3 + j / 3;
                if ((grids[index] & (1 << n)) > 0) return false;
                grids[index] |= (1 << n);

            }
        }
        return true;

    }