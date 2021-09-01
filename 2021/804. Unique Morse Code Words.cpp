class Solution {
public:
    string codes[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> count;
        for (string& w : words) {
            string key;
            for (char c : w) {
                key += codes[c - 'a'];
            }
            count.insert(key);
        }
        return count.size();
    }
};