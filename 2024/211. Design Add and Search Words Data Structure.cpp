struct TrieNode {
    bool isWord;
    vector<TrieNode*> next;
    TrieNode() {
        isWord = false;
        next.resize(26, NULL);
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (node->next[word[i] - 'a'] == NULL) {
                node->next[word[i] - 'a'] = new TrieNode();
            }
            node = node->next[word[i] - 'a'];
        }
        node->isWord = true;
    }

    bool search(string word) {
        queue<TrieNode*> queue;
        queue.push(root);
        int index = 0;
        for (; index < word.length() && !queue.empty(); index++) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TrieNode* node = queue.front();
                queue.pop();
                if (word[index] == '.') {
                    for (int j = 0; j < 26; j++) {
                        if (node->next[j] != NULL) {
                            if (index + 1 == word.length() &&
                                node->next[j]->isWord) {
                                return true;
                            }
                            queue.push(node->next[j]);
                        }
                    }
                } else if (node->next[word[index] - 'a'] != NULL) {
                    if (index + 1 == word.length() &&
                        node->next[word[index] - 'a']->isWord) {
                        return true;
                    }
                    queue.push(node->next[word[index] - 'a']);
                }
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