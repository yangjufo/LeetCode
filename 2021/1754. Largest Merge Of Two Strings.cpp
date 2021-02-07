class Solution {
public:
    string largestMerge(string word1, string word2) {
        int i = 0, j = 0;
        string merge;
        while (i < word1.length() && j < word2.length()) {
            int k = 0;
            while (i + k < word1.length() && j + k < word2.length() && word1[i + k] == word2[j + k]) {
                k++;
            }            
            if (j + k == word2.length() || word1[i + k] > word2[j + k]) {
                merge += word1[i];
                i++;
            } else {
                merge += word2[j];
                j++;
            }                        
        }
        if (i == word1.length()) {
            merge += word2.substr(j);
        } else {
            merge += word1.substr(i);
        }
        return merge;
    }
};