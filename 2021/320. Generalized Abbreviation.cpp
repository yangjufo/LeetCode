class Solution {
public:
    vector<string> res;
    vector<string> generateAbbreviations(string word) {
        backtrack(word, 0, "");
        return res;
    }
    
    void backtrack(string& word, int index, string curr) {
        if (index >= word.length()) {
            res.push_back(curr);
            return;
        }
        for (int i = index; i < word.length(); i++) {
            if (curr.empty() || !isdigit(curr.back())) {
                backtrack(word, i + 1, curr + to_string(i - index + 1));
            }                        
        }
        backtrack(word, index + 1, curr + word.substr(index, 1));
    }
};