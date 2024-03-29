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

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, int> count;
        for (int c : s) {
            count[c]++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (count[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};