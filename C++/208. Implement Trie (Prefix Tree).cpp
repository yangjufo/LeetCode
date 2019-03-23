struct Node {
    string val;
    map<char, Node*> children;    
    Node(): val("") {}
};

class Trie {
public:
    /** Initialize your data structure here. */
    Node* root;
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node;
        node = root;
        int index;
        for(index = 0; index < word.length(); index++){
            if (node->children.count(word[index]) != 0){
                node = node->children[word[index]];
            }
            else
                break;
        }
        for (;index < word.length(); index++){
            node->children.insert(pair<char, Node*>(word[index], new Node()));
            node = node->children[word[index]];
        }    
        node->val = word;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = root;
        int index;
        for (index = 0; index < word.length(); index++){
            if (node->children.count(word[index]) != 0){
                node = node->children[word[index]];
            }
            else
                return false;
        }        
        return node->val == word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = root;
        int index;
        for (index = 0; index < prefix.length(); index++){
            if (node->children.count(prefix[index]) != 0){
                node = node->children[prefix[index]];
            }
            else
                return false;
        }
        return true;
    }
};