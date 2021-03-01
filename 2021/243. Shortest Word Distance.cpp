class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int res = words.size();
        vector<int> index1, index2;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                index1.push_back(i);
            }
            if (words[i] == word2) {
                index2.push_back(i);
            }
        }
        
        for (int i : index1) {
            for (int j : index2) {
                res = min(abs(i - j), res);
            }
        }
        return res;
    }
};

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int res = words.size(), index1 = -1, index2 = -1;        
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                index1 = i;
            }
            if (words[i] == word2) {
                index2 = i;
            }
            if (index1 != -1 && index2 != -1) {
                res = min(abs(index1 - index2), res);
            }
        }                
        return res;
    }
};