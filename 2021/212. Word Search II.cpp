class Solution {

class TrieNode {
public:
    string word;
    TrieNode* next[26];    
    
    TrieNode() {
        word = "";
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
    
};
    
    int h[4] = {0, 0, 1, -1};
    int v[4] = {1, -1, 0, 0};
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {        
        TrieNode* root = new TrieNode();
        for (string word : words) {
            TrieNode* node = root;
            for (char c : word) {
                if (node->next[c - 'a'] == NULL) {
                    node->next[c - 'a'] = new TrieNode();
                }
                node = node->next[c - 'a'];
            }
            node->word = word;
        }        
        
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        vector<string> res;
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (root->next[board[i][j] - 'a'] != NULL) {
                    backtrack(board, i, j, root, visited, res);
                }
            }
        }
        
        return res;
    }        
    
    void backtrack(vector<vector<char>>& board, int x, int y, TrieNode* node, vector<vector<bool>>& visited, vector<string>& res) {                
        TrieNode* curr = node->next[board[x][y] - 'a'];
        
        if (!(curr->word).empty()) {
            res.push_back(curr->word);
            curr->word = "";
        }
        
        visited[x][y] = true;
        
        for (int i = 0; i < 4; i++) {
            int newX = x + h[i], newY = y + v[i];
            if (newX < 0 || newX >= board.size() || newY < 0 || newY >= board[0].size() || visited[newX][newY] || curr->next[board[newX][newY] - 'a'] == NULL) {
                continue;
            }
            backtrack(board, newX, newY, curr, visited, res);
        }
        
        visited[x][y] = false;                        
    }
    
};