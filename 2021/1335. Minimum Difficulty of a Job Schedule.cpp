class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if (jobDifficulty.size() < d) return -1;                
        int n = jobDifficulty.size();
        int dp[n + 1];
        for (int i = 0; i < n; i++) {
            dp[i] = 300'0001;
        }
        dp[n] = 0;
        int maxd;
        for (int i = 1; i <= d; i++) {            
            for (int j = 0; j <= n - i; j++) {
                maxd = 0;
                dp[j] = 300000 + 1;
                for (int k = j; k <= n - i; k++) {                    
                    maxd = max(maxd, jobDifficulty[k]);
                    dp[j] = min(dp[j], maxd + dp[k + 1]);
                }
                cout << dp[j] << " ";
            }
            cout << endl;
        }
        return dp[0];
        
    }
};