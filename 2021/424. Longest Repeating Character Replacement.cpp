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