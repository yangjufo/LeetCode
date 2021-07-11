class Solution {
public:
    int countPalindromicSubsequence(string s) {        
        int count = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            int i = 0, j = s.length() - 1;
            while (i < s.length() && s[i] != c) {
                i++;
            }
            while (j >= 0 && s[j] != c) {
                j--;
            }            
            vector<int> visited(26, false);
            for (int k = i + 1; k < j; k++) {
                if (!visited[s[k] - 'a']) {
                    count++;
                    visited[s[k] - 'a'] = true;
                }
            }            
        }
        return count;        
    }
};