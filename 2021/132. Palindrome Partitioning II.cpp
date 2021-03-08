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