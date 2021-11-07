class Solution {
public:
    int countVowelSubstrings(string& word) {
        int res = 0;
        for (int i = 0; i < word.length(); i++) {
            for (int j = 0; j < word.length(); j++) {
                vector<int> counts(26, 0);
                int k = i;
                for (; k <= j; k++) {
                    if (word[k] != 'a' && word[k] != 'e' && word[k] != 'i' && word[k] != 'o' && word[k] != 'u') {
                        break;
                    }
                    counts[word[k] - 'a']++;                    
                }
                if (k > j && counts['a' - 'a'] > 0 && counts['e' - 'a'] > 0 && counts['i' - 'a'] > 0 && counts['o' - 'a'] > 0 && counts['u' - 'a'] > 0) {
                    res++;
                }
            }
        }
        return res;
    }
};