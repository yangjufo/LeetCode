class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> countMap(26, 0);
        int start = 0, maxCount = 0, res = 0;
        for (int i = 0; i < s.length(); i++) {
            countMap[s[i] - 'A']++;
            if (countMap[s[i] - 'A'] > maxCount) {
                maxCount = countMap[s[i] - 'A'];
            }
            while (i - start + 1 - maxCount > k) {
                countMap[s[start] - 'A']--;                
                start++;
            }
            res = max(i - start + 1, res);
        }
        return res;
    }
};


class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counter(26, 0);
        int maxCount = 0, maxLen = 0, start = 0;
        for (int i = 0; i < s.length(); i++) {
            counter[s[i] - 'A']++;
            maxCount = max(maxCount, counter[s[i] - 'A']);
            while (i - start + 1 - maxCount > k) {
                counter[s[start] - 'A']--;
                start++;
            }
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};

class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0, maxCount = 0, maxLen = 0;
        vector<int> count(26, 0);
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'A']++;
            maxCount = max(maxCount, count[s[i] - 'A']);
            while (i - start + 1 - maxCount > k) {
                count[s[start] - 'A']--;
                start++;
            }
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};