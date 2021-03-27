class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<vector<int>> countB(B.size(), vector<int>(26, 0));
        vector<int> maxB(26, 0);
        for (int i = 0; i < B.size(); i++) {
            for (char c : B[i]) {
                countB[i][c - 'a']++;
                maxB[c - 'a'] = max(maxB[c - 'a'], countB[i][c - 'a']);
            }            
        }        
        vector<string> res;
        for (string& word : A) {
            int countA[26] = {};
            for (char c: word) {
                countA[c - 'a']++;
            }
            int i = 0;
            for (; i < 26; i++) {
                if (countA[i] < maxB[i]) {
                    break;
                }
            }
            if (i >= 26) {
                res.push_back(word);
            }
        }
        return res;
    }
};