class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int count = 0;
        unordered_set<char> first;
        for (int i = 0; i < s.length() - 2; i++) {
            if (first.find(s[i]) != first.end()) {
                continue;
            }
            first.insert(s[i]);
            unordered_set<char> second;
            for (int j = i + 1; j < s.length() - 1; j++) {
                if (second.find(s[j]) != second.end()) {
                    continue;
                }
                second.insert(s[j]);
                for (int k = j + 1; k < s.length(); k++) {
                    if (s[k] == s[i]) {
                        count++;
                        break;
                    }
                }
            }
        }
        return count;
    }
};