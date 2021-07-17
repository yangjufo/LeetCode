class Solution {
public:
    vector<vector<int>> dp;
    int getMoneyAmount(int n) {
        dp.resize(n, vector<int>(n + 1, 0));
        return dfs(1, n);
    }
    
    int dfs(int left, int right) {
        if (left >= right) return 0;
        if (dp[left][right] == 0) {
            int maximum = INT_MAX;
            for (int i = left; i <= right; i++) {
                maximum = min(maximum, max(dfs(left, i - 1), dfs(i + 1, right)) + i);
            }
            dp[left][right] = maximum;
        }        
        return dp[left][right];
        
    }
};