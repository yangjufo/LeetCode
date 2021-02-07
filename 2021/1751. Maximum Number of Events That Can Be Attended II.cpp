class Solution {
public:
    
    vector<vector<int>> dp;
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());
        dp.resize(n + 1, vector<int>(k + 1, -1));
        
        return helper(events, n, 0, k);
    }
    
    int helper(vector<vector<int>>& events, int n, int start, int k) {
        if (start >= n || k == 0) return 0;
        
        if (dp[start][k] > -1) return dp[start][k];
        
        int i = start + 1;
        while (i < n && events[i][0] <= events[start][1]) {
            i++;
        }
        
        dp[start][k] = max(helper(events, n, start + 1, k), events[start][2] + helper(events, n, i, k - 1));
        return dp[start][k];
    }
};