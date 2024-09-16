struct TrieNode {
    bool word;
    vector<TrieNode*> next;
    TrieNode(bool word_) {
        word = word_;
        next.resize(26, NULL);
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode(false);
    }

    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (node->next[word[i] - 'a'] == NULL) {
                node->next[word[i] - 'a'] = new TrieNode(false);
            }
            node = node->next[word[i] - 'a'];
            if (i + 1 == word.length()) {
                node->word = true;
            }
        }
    }

    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (node->next[word[i] - 'a'] == NULL) {
                return false;
            }
            node = node->next[word[i] - 'a'];
        }
        return node->word;
    }

    bool startsWith(string prefix) {
         TrieNode* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (node->next[prefix[i] - 'a'] == NULL) {
                return false;
            }
            node = node->next[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */