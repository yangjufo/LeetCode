class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), 0);
        for (int i = (int)questions.size() - 1; i >= 0; i--) {
            dp[i] = max(i + 1 == (int) questions.size() ? 0 : dp[i + 1], ((questions[i][1] + i + 1 > (int)questions.size() - 1) ? 0 : dp[i + questions[i][1] + 1]) + questions[i][0]);
        }
        return dp[0];
    }
};