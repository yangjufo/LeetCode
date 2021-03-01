class Solution {
public:    
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int index1 = -1, index2 = -1, res = words.size();
        for (int i = 0; i < words.size(); i++) {
            if (word1 != word2) {
                if (words[i] == word1) {
                    index1 = i;
                } 
                if (words[i] == word2) {
                    index2 = i;
                }
            } else {
                if (words[i] == word1) {
                    if (index1 > index2) {
                        index2 = i;
                    } else {
                        index1 = i;
                    }
                }
            }            
            if (index1 != -1 && index2 != -1) {
                res = min(res, abs(index1 - index2));
            }
        }
        return res;
    }
};

class Solution {
public:    
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int index1 = -1, index2 = -1, res = words.size();
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1 && (word1 != word2 || index1 <= index2)) {
                index1 = i;
            } else if (words[i] == word2) {
                index2 = i;
            }                                 
            if (index1 != -1 && index2 != -1) {
                res = min(res, abs(index1 - index2));
            }
        }
        return res;
    }
};