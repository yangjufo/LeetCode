class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, len = 0;
        unordered_set<char> seen;
        for (int i = 0; i < s.length(); i++) {
            while (seen.find(s[i]) != seen.end()) {
                seen.erase(s[start]);
                start += 1;
            }
            seen.insert(s[i]);
            len = max(len, i - start + 1);
        }
        return len;
    }
};