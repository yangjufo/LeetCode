class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0;
        while (i < word.length() && word[i] != ch) {
            i++;
        }
        if (i < word.length()) {
            reverse(word.begin(), word.begin() + i + 1);
        }        
        return word;
    }
};