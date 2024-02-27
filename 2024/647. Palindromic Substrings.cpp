class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        int count = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            dp[i][i] = true;
            count += 1;
            for (int j = i + 1; j < s.length(); j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = j == i + 1 ? true : dp[i + 1][j - 1];
                    if (dp[i][j]) {
                        count += 1;
                    }
                }
            }
        }
        return count;
    }
};