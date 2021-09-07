class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> built;
        string res;
        for (string& word : words) {
            if (word.length() == 1 || built.find(word.substr(0, (int)word.length() - 1)) != built.end()) {
                res = word.length() > res.length() ? word : res;
                built.insert(word);
            }            
        }
        return res;
    }
};