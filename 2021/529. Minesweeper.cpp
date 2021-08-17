class Solution {
public:
    int directions[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        dfs(board, click[0],click[1]);
        return board;
    }
    
    void dfs(vector<vector<char>>& board, int row, int col) {
        if (board[row][col] == 'M') {
            board[row][col] = 'X';
            return;
        }        
        int minCount = 0;
        for (int i = 0; i < 8; i++) {
            int newRow = row + directions[i][0], newCol = col + directions[i][1];
            if (newRow < 0 || newRow >= board.size() || newCol < 0 || newCol >= board[0].size() || board[newRow][newCol] != 'M') {
                continue;
            }
            minCount++;
        }
        if (minCount == 0) {
            board[row][col] = 'B';
            for (int i = 0; i < 8; i++) {
                int newRow = row + directions[i][0], newCol = col + directions[i][1];
                if (newRow < 0 || newRow >= board.size() || newCol < 0 || newCol >= board[0].size() || board[newRow][newCol] != 'E') {
                    continue;
                }            
                dfs(board, newRow, newCol);
            }
        } else {
            board[row][col] = minCount + '0';
        }                
    }
};