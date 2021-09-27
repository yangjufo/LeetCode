class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), maxCount = 0;
        vector<vector<int>> count(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            int curr = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'W') {
                    curr = 0;
                } else if (grid[i][j] == 'E') {
                    curr += 1;
                } else {
                    count[i][j] += curr;
                }    
                // cout << count[i][j] << " ";
            }        
            // cout << endl;
            curr = 0;
            for (int j = n - 1; j >= 0; j--) {                
                if (grid[i][j] == 'W') {
                    curr = 0;
                } else if (grid[i][j] == 'E') {
                    curr += 1;
                } else {
                    count[i][j] += curr;
                }
            }            
        }        
        for (int j = 0; j < n; j++) {
            int curr = 0;
            for (int i = 0; i < m; i++) {                
                if (grid[i][j] == 'W') {
                    curr = 0;
                } else if (grid[i][j] == 'E') {
                    curr += 1;
                } else {
                    count[i][j] += curr;
                }
            }
            curr = 0;
            for (int i = m - 1; i >= 0; i--) {            
                if (grid[i][j] == 'W') {
                    curr = 0;
                } else if (grid[i][j] == 'E') {
                    curr += 1;
                } else {
                    count[i][j] += curr;
                }
                maxCount = max(maxCount, count[i][j]);
            }
        }
        return maxCount;
    }
};

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            int curr = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'W') {
                    curr = 0;
                } else if (grid[i][j] == 'E') {
                    curr++;
                } else {
                    dp[i][j] = curr;
                }
            }
            curr = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 'W') {
                    curr = 0;
                } else if (grid[i][j] == 'E') {
                    curr++;
                } else {
                    dp[i][j] += curr;
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < n; j++) {
            int curr = 0;
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 'W') {
                    curr = 0;
                } else if (grid[i][j] == 'E') {
                    curr++;
                } else {
                    dp[i][j] += curr;
                }
            }
            curr = 0;
            for (int i = m - 1; i >= 0; i--) {
                if (grid[i][j] == 'W') {
                    curr = 0;
                } else if (grid[i][j] == 'E') {
                    curr++;
                } else {
                    dp[i][j] += curr;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};