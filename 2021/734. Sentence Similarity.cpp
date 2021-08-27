class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) return false;
        unordered_map<string, unordered_set<string>> pairMap;
        for (int i = 0; i < similarPairs.size(); i++) {
            pairMap[similarPairs[i][0]].insert(similarPairs[i][1]);
            pairMap[similarPairs[i][1]].insert(similarPairs[i][0]);
        }
        for (int i = 0; i < sentence1.size(); i++) {
            if (!isSimilar(sentence1[i], sentence2[i], similarPairs)) {
                return false;
            }
        }
        return true;
    }
    
    bool isSimilar(string& left, string& right, vector<vector<string>>& similarPairs) {
        if (left == right) return true;
        for (auto& p : similarPairs) {
            if ((p[0] == left && p[1] == right) || (p[0] == right && p[1] == left)) {
                return true;
            }
        }
        return false;
    }
};