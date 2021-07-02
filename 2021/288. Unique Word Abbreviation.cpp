class ValidWordAbbr {
public:
    unordered_map<string, int> abbr;
    vector<string> dict;
    ValidWordAbbr(vector<string>& dictionary) {        
        dict = dictionary;
        for (int i = 0; i < dictionary.size(); i++) {
            string& word = dictionary[i];
            string ab = word.substr(0, 1) + ((word.length() > 2) ? to_string(word.length() - 2) : "") + word.substr(word.length() -  1, 1);                                    
            if (abbr.find(ab) != abbr.end() && abbr[ab] != -1 && dict[abbr[ab]] != word) {                
                abbr[ab] = -1;
            } else {
                abbr[ab] = i;
            }            
        }
    }
    
    bool isUnique(string word) {
         string ab = word.substr(0, 1) + ((word.length() > 2) ? to_string(word.length() - 2) : "") + word.substr(word.length() - 1, 1);
        return abbr.find(ab) == abbr.end() || (abbr[ab] != -1 && dict[abbr[ab]] == word);                             
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */