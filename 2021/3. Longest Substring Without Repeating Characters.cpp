class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap;
        int start = 0, maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (charIndexMap.count(s[i]) && start < charIndexMap[s[i]] + 1) {
                start = charIndexMap[s[i]] + 1;
            }
            maxLen = max(maxLen, i - start + 1);
            charIndexMap[s[i]] = i;
        }
        return maxLen;
    }
};