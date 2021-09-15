class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        vector<double> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < prob.size(); i++) {
            for (int j = min(i + 1, target); j >= 0; j--) {
                dp[j] = dp[j] * (1 - prob[i]);
                if (j > 0) {
                    dp[j] += dp[j - 1] * prob[i];
                }
            }
        }
        return dp[target];
    }
};