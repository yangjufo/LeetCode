class TrieNode {
public:
    TrieNode* next[26];
    bool isWord;
    
    TrieNode() {
        isWord = false;
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
    
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* root = new TrieNode();
        for (string& word : dictionary) {
            TrieNode* node = root;
            for (char c : word) {
                if (node->next[c - 'a'] == NULL) {
                    node->next[c - 'a'] = new TrieNode();
                }
                node = node->next[c - 'a'];
            }
            node->isWord = true;
        }
        string curr, res;
        sentence += " ";
        for (char c : sentence) {
            if (c == ' ') {
                TrieNode* node = root;
                string key;
                for (char ch : curr) {
                    key += ch;
                    node = node->next[ch - 'a'];
                    if (node == NULL || node->isWord) {
                        break;
                    }
                }                
                res += (node == NULL ? curr : key) + " ";
                curr.clear();
            } else {
                curr += c;
            }
        }
        res.pop_back();
        return res;
    }            
};