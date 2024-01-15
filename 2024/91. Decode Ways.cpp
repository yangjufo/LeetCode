class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '0') {
                if (s[i - 1] != '1' && s[i - 1] != '2') {
                    return 0;
                }
                dp[i + 1] = dp[i - 1];
            } else {
                dp[i + 1] = dp[i];
                if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >='0' && s[i] <= '6')) {
                    dp[i + 1] += dp[i - 1];
                }
            }
        }
        return dp[s.length()];
    }
};