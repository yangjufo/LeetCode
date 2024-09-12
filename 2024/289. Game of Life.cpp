class Solution {
public:
    int dirs[8][2] = {{0, -1}, {-1, -1}, {-1, 0}, {1, -1},
                      {0, 1},  {1, 1},   {1, 0},  {-1, 1}};
    void gameOfLife(vector<vector<int>>& board) {
        int live2dead = -1, dead2live = -2;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                int liveCount = 0;
                for (int k = 0; k < 8; k++) {
                    int x = i + dirs[k][0], y = j + dirs[k][1];
                    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
                        continue;
                    }
                    if (board[x][y] == 1 || board[x][y] == live2dead) {
                        liveCount += 1;
                    }
                }
                if (board[i][j] == 1 && (liveCount < 2 || liveCount > 3)) {
                    board[i][j] = live2dead;
                } else if(board[i][j] == 0 && (liveCount == 3)) {
                    board[i][j] = dead2live;
                }
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == live2dead) {
                    board[i][j] = 0;
                } else if (board[i][j] == dead2live) {
                    board[i][j] = 1;
                }
            }
        }
    }
};