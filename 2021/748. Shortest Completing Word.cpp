class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> count(26, 0);
        for (char c : licensePlate) {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                count[tolower(c) - 'a']++;
            }
        }
        string cand;
        for (string& word : words) {
            vector<int> wCount(26, 0);
            for (char c : word) {
                wCount[c - 'a']++;                
            }
            int i = 0;
            while (i < 26 && wCount[i] >= count[i]) {
                i++;
            }
            if (i >= 26 && (cand.empty() || word.length() < cand.length())) {
                cand = word;
            }
        }
        return cand;
    }
};