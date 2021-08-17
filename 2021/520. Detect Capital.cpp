class Solution {
public:
    bool detectCapitalUse(string word) {
        bool lowerFound = false, upperFound = false;
        for (int i = 0; i < word.length(); i++) {            
            if (word[i] >= 'A' && word[i] <= 'Z') {
                if (i != 0) {
                    upperFound = true;
                }                
                if (lowerFound) return false;
            } else {
                lowerFound = true;
                if (upperFound) return false;
            }            
        }
        return true;
    }
};