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

class Solution {
public:
    bool detectCapitalUse(string word) {
        bool canLow = true, canUp = true;
        if (word[0] >= 'a' && word[0] <= 'z') {
            canUp = false;
        }
        for (int i = 1; i < word.length(); i++) {
            if (word[i] >= 'a' && word[i] <= 'z') {
                if (!canLow) return false;
                canUp = false;
            } else {
                if (!canUp) return false;
                canLow = false;
            }
        }
        return true;
    }
};