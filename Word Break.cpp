class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int word[s.length()];
        for (int i = 0; i < s.length(); i++) {
            word[i] = 0;
            for (int j = i; j > -1; j--) {
                if (find(wordDict.begin(), wordDict.end(), s.substr(j, i - j + 1)) != wordDict.end() &&
                    (j == 0 || word[j - 1] != 0)) {
                    word[i] = 1;
                    break;
                }
            }

        }
        return word[s.length() - 1] == 1;
    }
};