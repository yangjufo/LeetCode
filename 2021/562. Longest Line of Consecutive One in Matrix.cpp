class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int maxLen = 0;
        int dp[M[0].size()][4];        
        for (int j = 0; j < M[0].size(); j++) {
            dp[j][0] = dp[j][1] = dp[j][2] = dp[j][3] = 0;
        }
        for (int i = 0; i < M.size(); i++) {
            int old2 = 0;
            for (int j = 0; j < M[0].size(); j++) {
                if (M[i][j] == 1) {
                    dp[j][0] = j == 0 ? 1 : dp[j - 1][0] + 1;
                    dp[j][1] = i == 0 ? 1 : dp[j][1] + 1;
                    int tmp = dp[j][2];
                    dp[j][2] = j == 0 ? 1 : old2 + 1;
                    old2 = tmp;
                    dp[j][3] = j == M[0].size() - 1 ? 1 : dp[j + 1][3] + 1;
                    maxLen = max(maxLen, max(dp[j][0], max(dp[j][1], max(dp[j][2], dp[j][3]))));
                } else {
                    old2 = dp[j][2];
                    dp[j][0] = dp[j][1] = dp[j][2] = dp[j][3] = 0;
                }
            }
        }
        return maxLen;
    }
};