class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> sCount;
        int start = 0, disCount = 0, maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            sCount[s[i]]++;
            if (sCount[s[i]] == 1) disCount++;
            while (disCount > k && start <= i) {
                sCount[s[start]]--;
                if (sCount[s[start]] == 0) {
                    disCount--;
                }
                start++;
            }           
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};