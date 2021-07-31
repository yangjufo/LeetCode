class TrieNode {
public:
    int val;
    TrieNode* next[26];        
    
    TrieNode() {
        val = 0;
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }        
};

class MapSum {
public:
    /** Initialize your data structure here. */
    TrieNode* root = new TrieNode();
    unordered_map<string, int> valMap;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        if (valMap.find(key) != valMap.end()) {
            val -= valMap[key];
        }
        valMap[key] += val;
        TrieNode* node = root;        
        for (char c : key) {
            if (node->next[c - 'a'] == NULL) {
                node->next[c - 'a'] = new TrieNode();
            }
            node = node->next[c - 'a'];
            node->val += val;
        }        
    }
    
    int sum(string prefix) {        
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->next[c - 'a'] == NULL) {
                return 0;
            }
            node = node->next[c - 'a'];            
        }
        return node->val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */