class Solution {
public:    
    int minCut(string s) {
        int N = s.length();        
        vector<vector<bool>> dp(N, vector<bool>(N, false));
        vector<int> cuts(N, N);
        for (int i = 0; i < N; i++) {
            int minCount = i;
            for (int j = 0; j <= i; j++) {
                if (s[j] == s[i]) {
                    dp[j][i] = (j + 1 <= i - 1) ? dp[j + 1][i - 1] : true;
                    if (dp[j][i]) {
                        minCount = j == 0 ? 0 : min(minCount, cuts[j - 1] + 1);
                    }
                } 
            }
            cuts[i] = minCount;            
        } 
        return cuts[N - 1];
    }               
};

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> palindromes(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    palindromes[i][j] = (i + 1 < j - 1) ? palindromes[i + 1][j - 1] : true;
                }
            }
        }
        vector<int> cuts(n, n);
        for (int i = 0; i < n; i++) {
            cuts[i] = i;
            for (int j = 0; j <= i; j++) {
                if (palindromes[j][i]) {
                    cuts[i] = j == 0 ? 0 : min(cuts[i], cuts[j - 1] + 1);
                }
            }
        }
        return cuts[n - 1];
    }
};