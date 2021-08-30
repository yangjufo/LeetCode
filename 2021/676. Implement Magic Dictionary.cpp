class MagicDictionary {
public:
    unordered_set<string> dict;
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        dict.insert(dictionary.begin(), dictionary.end());
    }
    
    bool search(string searchWord) {
        for (int i = 0; i < searchWord.length(); i++) {
            char tmp = searchWord[i];
            for (int j = 0; j < 26; j++) {
                if (j + 'a' == tmp) continue;
                searchWord[i] = j + 'a';
                if (dict.find(searchWord) != dict.end()) {
                    return true;
                }
            }            
            searchWord[i] = tmp;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */