class Solution {
public:
    int dirs[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, 0, i, j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int index, int row, int col) {
        if (index + 1 >= word.length()) {
            return true;
        }
        int tmp = board[row][col];
        board[row][col] = '#';
        for (int i = 0; i < 4; i++) {
            int nr = row + dirs[i][0], nc = col + dirs[i][1];
            if (nr < 0 || nr >= board.size() || nc < 0 || nc >= board[0].size() || board[nr][nc] != word[index + 1]) {
                continue;
            }
            if (dfs(board, word, index + 1, nr, nc)) {
                return true;
            }
        }
        board[row][col] = tmp;
        return false;
    }
};