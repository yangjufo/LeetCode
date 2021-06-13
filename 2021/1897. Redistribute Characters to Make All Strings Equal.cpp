class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> count(26, 0);
        for (string& word : words) {
            for (char c : word) {
                count[c - 'a']++;
            }
        }        
        for (int i = 0; i < 26; i++) {
            if (count[i] <= 0) continue;            
            if (count[i] % words.size() != 0) return false;
        }
        return true;
    }
};