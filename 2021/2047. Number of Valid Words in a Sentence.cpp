class Solution {
public:
    int countValidWords(string sentence) {
        int start = 0, count = 0, end = 0;
        while (end < sentence.length()) {
            while (start < sentence.length() && sentence[start] == ' ') {
                start++;
            }
            end = start;
            while (end < sentence.length() && sentence[end] != ' ') {
                end++;                
            }
            if (isValid(sentence.substr(start, end - start))) {
                count++;
            }
            start = end + 1;        
        }
        return count;
    }
    
    bool isValid(string word) {
        bool seenH = false, cSeen = false;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == '-') {
                if (seenH || i == 0 || i + 1 == word.length() || !(word[i - 1] >= 'a' && word[i - 1] <= 'z' && word[i + 1] >= 'a' && word[i + 1] <= 'z')) {
                    return false;                    
                }
                seenH = true;
                cSeen = true;
            } else if (word[i] == ',' || word[i] == '!' || word[i] == '.') {
                if (i + 1 != word.length()) {
                    return false;
                }
                cSeen = true;
            } else if (word[i] >= '0' && word[i] <= '9') {                
                return false;
            } else if (word[i] >= 'a' && word[i] <= 'z') {
                cSeen = true;
            }   
        }
        return cSeen;
    }
};