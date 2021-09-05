class Solution {
public:    
    int mod = 1e9 + 7;
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n = nextVisit.size();
        vector<pair<long long, long long>> dp(n);
        dp[0] = {0, 1};
        for (int i = 1; i < n; i++) {
            dp[i].first = (dp[i - 1].second + 1) % mod;
            if (nextVisit[i] == i) {
                dp[i].second = (dp[i].first + 1) % mod;
            } else {
                dp[i].second = (dp[i].first + dp[i - 1].second + mod - dp[nextVisit[i]].first + 2) % mod;
            }      
        }
        return dp[n - 1].first;
    }
};