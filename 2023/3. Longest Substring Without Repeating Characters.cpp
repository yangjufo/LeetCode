class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, max_length = 0;
        unordered_set<char> seen;
        for (int i = 0; i < s.length(); i++) {
            max_length = max(max_length, i - start);
            while (seen.find(s[i]) != seen.end()) {
                seen.erase(s[start]);
                start++;
            }
            seen.insert(s[i]);
        }
        return max(max_length, (int)s.length() - start);
    }
};