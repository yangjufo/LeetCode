class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int w1 = 0, w2 = 0, s1 = 0, s2 = 0;
        while (w1 < word1.size() && w2 < word2.size()) {
            while (s1 < word1[w1].size() && s2 < word2[w2].size() && word1[w1][s1] == word2[w2][s2]) {
                s1++;
                s2++;
            }
            if (s1 < word1[w1].size() && s2 < word2[w2].size()) return false;
            if (s1 >= word1[w1].size()) {
                w1++;
                s1 = 0;
            }
            if (s2 >= word2[w2].size()) {
                w2++;
                s2 = 0;
            }
        }
        return (w1 >= word1.size() && w2 >= word2.size());
    }
};