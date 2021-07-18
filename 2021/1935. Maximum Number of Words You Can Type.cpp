class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> broken(26, false);
        for (char c : brokenLetters) {
            broken[c - 'a'] = true;
        }
        int count = 0;
        bool type = true;
        for (char c : text) {
            if (c == ' ') {
                if (type) {
                    count++;
                }
                type = true;
            } else if (broken[c - 'a']) {
                type = false;
            }            
        }    
        return count + (type ? 1 : 0);
    }
};