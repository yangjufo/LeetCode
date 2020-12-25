class Solution {
public:
    bool isAnagram(string s, string t) {
        int sCount[26], tCount[26];
        for (int i = 0; i < 26; i++) {
            sCount[i] = 0;
            tCount[i] = 0;
        }
        
        for (char c : s) {
            sCount[c - 'a']++;
        }
        for (char c : t) {
            tCount[c - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            if (sCount[i] != tCount[i]) {
                return false;
            }
        }
        
        return true;
    }
};