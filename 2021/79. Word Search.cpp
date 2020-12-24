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