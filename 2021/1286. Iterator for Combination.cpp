class CombinationIterator {
public:
    vector<string> combs;
    int length, index;
    CombinationIterator(string characters, int combinationLength) {        
        this->length = combinationLength;
        index = 0;
        backtrack(characters, "", 0);
    }
    
    string next() {
        index++;
        return combs[index - 1];
    }
    
    bool hasNext() {
        return index < combs.size();
    }
    
    void backtrack(string& chars, string curr, int start) {                
        if (curr.length() == length) {   
            combs.push_back(curr);            
        } else {
            for (int i = start; i < chars.length(); i++) {                                
                backtrack(chars, curr + chars[i], i + 1);                
            }
        }
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */