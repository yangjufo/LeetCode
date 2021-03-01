class WordDistance {
public:
    unordered_map<string, vector<int>> indexMap;
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            indexMap[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int>& index1 = indexMap[word1], &index2 = indexMap[word2];
        int l1 = 0, l2 = 0, res = INT_MAX;
        while (l1 < index1.size() && l2 < index2.size()) {
            res = min(res, abs(index1[l1] - index2[l2]));
            if (index1[l1] > index2[l2]) {
                l2++;
            } else {
                l1++;
            }
        }
        return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */