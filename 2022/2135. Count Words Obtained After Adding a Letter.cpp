class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> sBits;
        for (string& s : startWords) {
            int mask = 0;
            for (char c : s) {
                mask |= (1 << (c - 'a'));
            }
            for (int i = 0; i < 26; i++) {
                if ((mask & (1 << i)) == 0) {
                    sBits.insert(mask | (1 << i));
                }
            }
        }

        int count = 0;
        for (string& s : targetWords) {
            int mask = 0;
            for (char c : s) {
                mask |= (1 << (c - 'a'));
            }
            if (sBits.find(mask) != sBits.end()) {
                count++;
            }
        }
        return count;
    }
};