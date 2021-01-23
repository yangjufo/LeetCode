class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) return false;
        int count1[26], count2[26];
        memset(count1, 0, sizeof(count1));
        memset(count2, 0, sizeof(count2));
        for (int i = 0; i < word1.length(); i++) {
            count1[word1[i] - 'a']++;        
            count2[word2[i] - 'a']++;
        }        
        for (int i = 0; i < 26; i++) {
            if ((count1[i] == 0 && count2[i] > 0) || (count2[i] == 0 && count1[i] > 0))
                return false;
        }
        sort(count1, count1 + 26);
        sort(count2, count2 + 26);
        return equal(std::begin(count1), std::end(count1), std::begin(count2));
    }
};