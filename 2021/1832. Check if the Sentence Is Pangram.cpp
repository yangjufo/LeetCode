class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> counts(26, 0);
        for (int c : sentence) {
            counts[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (counts[i] <= 0) return false;
        }
        return true;
    }
};