class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int wi = 0, ai = 0;
        while (wi < word.length() && ai < abbr.length()) {
            if (isdigit(abbr[ai])) {
                if (abbr[ai] == '0') {
                    return false;
                }
                int num = 0;
                while (ai < abbr.length() && isdigit(abbr[ai])) {
                    num = num * 10 + (abbr[ai] - '0');
                    ai += 1;
                }
                wi += num;
            }
            if (wi < word.length() && ai < abbr.length()) {
                if(word[wi] != abbr[ai]) {
                    return false;
                }
                wi += 1;
                ai += 1;
            }
        }
        return wi == word.length() && ai == abbr.length();
    }
};