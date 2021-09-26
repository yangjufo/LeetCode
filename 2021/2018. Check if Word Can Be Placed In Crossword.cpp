class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            int j = 0;
            while (j + word.length() <= n) {
                while (j + word.length() <= n && board[i][j] == '#') {
                    j++;
                }
                if (j + word.length() > n) {
                    break;
                }
                int index = 0;
                while (index < word.length() && (board[i][j] == ' ' || (board[i][j] == word[index]))) {
                    j++;
                    index++;
                }
                if (index >= word.length() && (j >= n || board[i][j] == '#')) {
                    return true;
                }
                while (j + word.length() <= n && board[i][j] != '#') {
                    j++;
                }
            }
            j = n - 1;
            while (word.length() <= j + 1) {
                while (word.length() <= j + 1 && board[i][j] == '#') {
                    j--;
                }
                if (word.length() > j + 1) {
                    break;
                }
                int index = 0;
                while (index < word.length() && (board[i][j] == ' ' || (board[i][j] == word[index]))) {
                    j--;
                    index++;
                }
                if (index >= word.length() && (j < 0 || board[i][j] == '#')) {
                    return true;
                }
                while (word.length() <= j + 1 && board[i][j] != '#') {
                    j--;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            int i = 0;
            while (i + word.length() <= m) {
                while (i + word.length() <= m && board[i][j] == '#') {
                    i++;
                }                
                if (i + word.length() > m) {
                    break;
                }
                int index = 0;                
                while (index < word.length() && (board[i][j] == ' ' || (board[i][j] == word[index]))) {
                    i++;
                    index++;
                }               
                if (index >= word.length() && (i >= m || board[i][j] == '#')) {
                    return true;
                }            
                while (i + word.length() <= m && board[i][j] != '#') {
                    i++;
                }
            }            
            i = m - 1;
            while (word.length() <= i + 1) {
                while (word.length() <= i + 1 && board[i][j] == '#') {
                    i--;
                }                
                if (word.length() > i + 1) {
                    break;
                }
                int index = 0;       
                while (index < word.length() && (board[i][j] == ' ' || (board[i][j] == word[index]))) {
                    i--;
                    index++;
                }             
                if (index >= word.length() && (i < 0 || board[i][j] == '#')) {
                    return true;
                }            
                while (word.length() <= i + 1 && board[i][j] != '#') {
                    i--;
                }
            }
        }
        return false;
    }
};