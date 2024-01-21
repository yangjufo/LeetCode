class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <=n; j++) {
                dp[i][j] = min(min(abs(i - j), abs(x - i) + abs(j - y) + 1), abs(y - i) + abs(x - j) + 1);
            }
        }
        vector<int> res(n, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                res[dp[i][j] - 1] += 2;
            }
        }
        return res;
    }
};