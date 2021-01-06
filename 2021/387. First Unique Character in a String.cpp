class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> sCount
        for (char c : s) {
            sCount[c]++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (sCount[s[i]] == 1) return i;
        }
        
        return -1;
    }
};