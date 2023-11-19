class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> counts;
        int maxCount = 0;
        for (char c : s) {
            counts[c] += 1;
            maxCount = max(maxCount, counts[c]);
        }
        vector<vector<char>> freq(maxCount + 1);
        for (auto& [ch, c] : counts) {
            freq[c].push_back(ch);
        }
        string res;
        for (int i = freq.size() - 1; i >= 0; i--) {
            for (char c : freq[i]) {
                res += string(i, c);
            }
        }
        return res;

    }
};