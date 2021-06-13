class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<vector<long>> dp(n + 1, vector<long>(n + 1, 0));
        dp[0][0] = startFuel;
        for (int i = 0; i < stations.size(); i++) {            
            for (int j = 0; j <= i + 1; j++) {
                if (stations[i][0] <= dp[i][j]) {
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                    dp[i + 1][j + 1] = dp[i][j] + stations[i][1];
                }
            }
        }
        for (int j = 0; j <= n; j++) {
            if (dp[n][j] >= target) {
                return j;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {        
        int n = stations.size();
        vector<long> dp(n + 1);
        dp[0] = startFuel;
        for (int i = 0; i < stations.size(); i++) {            
            for (int j = i; j >= 0; j--) {
                if (stations[i][0] <= dp[j]) {                    
                    dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
                }                
            }            
        }
        for (int j = 0; j <= n; j++) {
            if (dp[j] >= target) {
                return j;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> gases;
        int stops = 0, prev = 0, fuel = startFuel;
        for (vector<int>& station : stations) {
            int location = station[0], gas = station[1];
            fuel -= location - prev;
            while (!gases.empty() && fuel < 0) {
                fuel += gases.top();
                gases.pop();
                stops++;
            }
            
            if (fuel < 0) return -1;
            gases.push(gas);
            prev = location;
        }
        
        fuel -= target - prev;
        while (!gases.empty() && fuel < 0) {
            fuel += gases.top();
            gases.pop();
            stops++;
        }
        if (fuel < 0) return -1;
        return stops;
    }
};