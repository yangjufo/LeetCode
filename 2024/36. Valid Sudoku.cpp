class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> rows(9, 0), cols(9, 0), grids(9, 0);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int bit = (1 << (board[i][j] - '0'));
                if ((rows[i] & bit) > 0 || (cols[j] & bit) > 0 ||
                    (grids[i / 3 * 3 + j / 3] & bit) > 0) {
                    return false;
                }
                rows[i] |= bit;
                cols[j] |= bit;
                grids[i / 3 * 3 + j / 3] |= bit;
            }
        }
        return true;
    }
};