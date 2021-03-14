class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int disCount = 0, counter[256], start = 0, maxLen = 0;
        fill(counter, counter + 256, 0);
        for (int i = 0; i < s.length(); i++) {
            counter[s[i]]++;
            if (counter[s[i]] == 1) {
                disCount++;
            }
            while (disCount > 2) {
                counter[s[start]]--;
                if (counter[s[start]] == 0) {
                    disCount--;
                }
                start++;
            }
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};