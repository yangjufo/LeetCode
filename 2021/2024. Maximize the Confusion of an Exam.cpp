class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int start = 0, maxLen = 0, kT = k;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'T') {
                kT--;
            }
            while (kT < 0) {
                if (s[start] == 'T') {
                    kT++;
                }
                start++;
            }
            maxLen = max(maxLen, i - start + 1);
        }
        start = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'F') {
                k--;
            }
            while (k < 0) {
                if (s[start] == 'F') {
                    k++;
                }
                start++;
            }
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};