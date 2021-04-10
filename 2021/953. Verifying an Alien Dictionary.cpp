class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int indexes[26];
        for (int i = 0; i < order.length(); i++) {
            indexes[order[i] - 'a'] = i;
        }
        for (int i = 1; i < words.size(); i++) {
            int j = 0;
            while (j < words[i - 1].length() && j < words[i].length()) {
                if (words[i - 1][j] == words[i][j]) {
                    j++;
                } else {
                    if (indexes[words[i - 1][j] - 'a'] > indexes[words[i][j] - 'a']) {
                        return false;
                    }
                    break;
                }
            }
            if (j < words[i - 1].length() && j == words[i].length()) return false;
        }
        return true;
    }
};