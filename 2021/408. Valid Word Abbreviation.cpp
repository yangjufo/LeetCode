class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        while (i < word.length() && j < abbr.length()) {
            int num = 0;
            while (j < abbr.length() && abbr[j] >= '0' && abbr[j] <= '9') {
                if (num == 0 && abbr[j] == '0') return false;
                num = num * 10 + abbr[j] - '0';
                j++;
            }
            if (num == 0) {
                if (word[i] != abbr[j]) {
                    return false;
                }
                i++;
                j++;
            } else {
                i += num;                  
            }            
        }
        return i == word.length() && j == abbr.length();
    }
};