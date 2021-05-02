class TrieNode {
public:
    TrieNode *next[26];
    vector<int> words;
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
};

class WordFilter {
public:
    TrieNode *preRoot = new TrieNode(), *sufRoot = new TrieNode();
    vector<string> dict;
    WordFilter(vector<string>& words) {
        dict = words;
        for (int i = 0; i < words.size(); i++) {
            TrieNode* node = preRoot;
            for (int j = 0; j < words[i].length(); j++) {
                int index = words[i][j] - 'a';
                if (node->next[index] == NULL) {
                    node->next[index] = new TrieNode();
                }                
                node = node->next[index];
                node->words.push_back(i);
            }
            node = sufRoot;
            for (int j = words[i].length() - 1; j >=0; j--) {
                int index = words[i][j] - 'a';
                if (node->next[index] == NULL) {
                    node->next[index] = new TrieNode();
                }                
                node = node->next[index];
                node->words.push_back(i);
            }
        }        
    }
    
    int f(string prefix, string suffix) {        
        TrieNode *preNode = preRoot, *sufNode = sufRoot;
        for (int i = 0; i < prefix.length() && preNode != NULL; i++) {
            preNode = preNode->next[prefix[i] - 'a'];
        }
        if (preNode == NULL) return -1;
        for (int i = suffix.length() - 1; i >= 0 && sufNode != NULL; i--) {
            sufNode = sufNode->next[suffix[i] - 'a'];
        }
        if (sufNode == NULL) return -1;
        
        int i = preNode->words.size() - 1, j = sufNode->words.size() - 1;
        while (i >= 0 && j >= 0) {
            if (preNode->words[i] == sufNode->words[j]) return preNode->words[i];
            if (preNode->words[i] > sufNode->words[j]) i--;
            else j--;
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */