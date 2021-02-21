class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        string res;
        while (i < word1.length() && i < word2.length()) {
            res += word1[i];
            res += word2[i];
            i++;
        }
        if (i < word1.length()) res += word1.substr(i);
        if (i < word2.length()) res += word2.substr(i);
        return res;
    }
};