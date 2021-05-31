class TrieNode {
public:
    vector<string> words;
    vector<TrieNode*> next;
    
    TrieNode() {
        next.resize(26, NULL);
    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        TrieNode* root = new TrieNode();
        for (string p : products) {
            insert(root, p);
        }
        vector<vector<string>> res;
        for (char c : searchWord) {
            if (root == NULL || root->next[c - 'a'] == NULL) {
                res.push_back({});
                root = NULL;
            } else {
                root = root->next[c - 'a'];
                vector<string> curr;
                for (int i = 0; i < 3 && i < root->words.size(); i++) {
                    curr.push_back(root->words[i]);
                }
                res.push_back(curr);
            }
        }
        return res;
    }
    
    void insert(TrieNode* node, string& word) {        
        for (char c : word) {            
            if (node->next[c - 'a'] == NULL) {
                node->next[c - 'a'] = new TrieNode();
            }
            node = node->next[c - 'a'];
            node->words.push_back(word);
        }
    }
};