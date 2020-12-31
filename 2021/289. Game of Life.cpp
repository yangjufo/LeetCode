class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = (m == 0) ? 0 : board[0].size();
        if (m == 0 || n == 0) return;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int count = 0; 
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx == 0 && dy == 0) continue;
                        int x = i + dx, y = j + dy;
                        if (x >= 0 && x < m && y >= 0 && y < n) {                        
                            count += board[x][y] >= 0 
                                ? board[x][y]
                                : (board[x][y] == -1 || board[x][y] == -2) ? 0 : 1;
                        }
                    }
                    
                }
                                    
                board[i][j] = (board[i][j] == 1)
                    ? ((count < 2 || count > 3) ? -3 : -4)
                    : ((count == 3) ? -2 : -1);
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = (board[i][j] == -1 || board[i][j] == -3) ? 0: 1;
            }
        }
    }
};