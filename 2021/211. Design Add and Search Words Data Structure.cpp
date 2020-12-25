class WordDictionary {   

class Trie {
public:
    bool isEnd;
    Trie* next[26];

    Trie() {
        isEnd = false;

        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }

};
    
public:
    Trie* root;    
    
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie* node = root;
        for (char c : word) {
            if (node->next[c - 'a'] == NULL) {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
    
    bool dfs(string& word, int start, Trie* node) {
        if (node == NULL) return false;
        if (start >= word.length()) return node->isEnd;
                
        if (word[start] == '.') {
            for (int i = 0; i < 26; i++) {
                if (dfs(word, start + 1, node->next[i])) return true;
            }
        } else {
            if (node->next[word[start] - 'a'] != NULL) {
                return dfs(word, start + 1, node->next[word[start] - 'a']);
            }
        }
        
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */