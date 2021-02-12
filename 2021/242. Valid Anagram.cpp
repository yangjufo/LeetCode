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


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int sCount[26], tCount[26];
        fill(sCount, sCount + 26, 0);
        fill(tCount, tCount + 26, 0);
        
        for (int i = 0; i < s.length(); i++) {
            sCount[s[i] - 'a']++;
            tCount[t[i] - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            if (sCount[i] != tCount[i]) return false;
        }
        
        return true;
    }
};