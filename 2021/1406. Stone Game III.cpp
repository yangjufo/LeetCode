class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, INT_MIN);
        for (int i = n - 1; i >= 0; i--) {
            for (int k = i, take = 0; k < i + 3 && k < n; k++) {
                take += stoneValue[k];                
                dp[i] = max(dp[i], take - (k + 1 < n ? dp[k + 1] : 0));
            }            
        }
        return (dp[0] > 0) ? "Alice" : (dp[0] == 0 ? "Tie" : "Bob");
    }
};