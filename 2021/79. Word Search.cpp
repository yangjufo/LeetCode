class Solution {
public:
    int v[4] = {0, 0, 1, -1};
    int h[4] = {1, -1, 0, 0};
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = (m == 0) ? 0 : board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {                
                if (dfs(board, m, n, word, 0, visited, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, int m, int n, string& word, int index, vector<vector<bool>>& visited, int x, int y) {      
        if (index >= word.length()){
             return true;
        }
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || board[x][y] != word[index]) {
            return false;
        }
        
        visited[x][y] = true;                                                
        
        for (int i = 0; i < 4; i++) {            
           if (dfs(board, m, n, word, index + 1, visited, x + h[i], y + v[i])) {
               return true;
           }
        }
        
        visited[x][y] = false;
        return false;
    }
};


class Solution {
public:
    
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, int row, int col, string& word, int index) {
        if (index >= word.length()) return true;
        
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index]) return false;
        
        board[row][col] = '#';
        
        bool found = false;
        for (int i = 0; i < 4 && !found; i++) {
            int newRow = row + directions[i][0];
            int newCol = col + directions[i][1];
            found = dfs(board, newRow, newCol, word, index + 1);            
        }
        
        board[row][col] = word[index];
        return found;
    }
};

class Solution {
public:
    int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    vector<vector<bool>> visited;
    bool exist(vector<vector<char>>& board, string word) {        
        visited.resize(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, int row, int col, string word, int index) {
        if (board[row][col] != word[index] || visited[row][col]) return false;
        if (index + 1 >= word.length()) return word[index] == board[row][col];
        visited[row][col] = true;
        for (int i = 0; i < 4; i++) {
            int newRow = row + directions[i][0], newCol = col + directions[i][1];
            if (newRow < 0 || newRow >= board.size() || newCol < 0 || newCol >= board[0].size()) {
                continue;
            }            
            if (dfs(board, newRow, newCol, word, index + 1)) {
                return true;
            }                        
        }
        visited[row][col] = false;
        return false;
    }
};

class Solution {
public:
    int directions[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (backtrack(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool backtrack(vector<vector<char>>& board, string& word, int index, int row, int col) {
        if (index >= word.length()) {
            return true;
        }
        if (board[row][col] != word[index]) {
            return false;
        }        
        int tmp = board[row][col];
        board[row][col] = '#';
        for (int i = 0; i < 4; i++) {
            int newRow = row + directions[i][0], newCol = col + directions[i][1];
            if (newRow < 0 || newRow >= board.size() || newCol < 0 || newCol >= board[0].size()) {
                continue;                
            }
            if (backtrack(board, word, index + 1, newRow, newCol)){
                return true;
            }
        }
        board[row][col] = tmp;
        return index + 1 >= word.length();
    }
};