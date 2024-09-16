class Solution {
public:
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    board[i][j] = '#';
                    if (dfs(board, i, j, word, 1)) {
                        return true;
                    }
                    board[i][j] = word[0];
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int x, int y, string& word,
             int index) {
        if (index >= word.length()) {
            return true;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dirs[i][0], ny = y + dirs[i][1];
            if (nx < 0 || nx >= board.size() || ny < 0 ||
                ny >= board[0].size() || board[nx][ny] != word[index]) {
                    continue;
            }
            board[nx][ny] = '#';
            if (dfs(board, nx, ny, word, index + 1)) {
                return true;
            }
            board[nx][ny] = word[index];
        }
        return false;
    }
};