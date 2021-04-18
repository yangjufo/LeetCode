class Solution {
public:
    string minWindow(string S, string T) {
        int m = S.length(), n = T.length();
        vector<vector<int>> dp(m, vector<int>(n, m));
        int minStart = m, minLen = m;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (S[i] == T[j]) {
                    if (i != 0 && j != 0) {
                        dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + 1;
                    } else {
                        dp[i][j] = (j == 0) ? 1 : m;
                    }                   
                    if (j == n - 1 && dp[i][j] < minLen) {                        
                        minLen = dp[i][j];
                        minStart = i - dp[i][j] + 1;
                    }
                } else {
                    dp[i][j] = (i == 0) ? m : dp[i - 1][j] + 1;
                }
            }
        }
        return S.substr(minStart, minLen);
    }
};

class Solution {
public:
    string minWindow(string S, string T) {
        string res;
        int j = 0;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == T[j]) {
                j++;
                if (j >= T.length()) {
                    int end = i + 1;
                    j--;
                    while (j >= 0) {
                        if (S[i] == T[j]) {
                            j--;
                        }
                        i--;
                    }
                    i++;
                    string tmp = S.substr(i, end - i);
                    if (res.length() == 0 || tmp.length() < res.length()) {
                        res = tmp;
                    }
                    j = 0;
                }
            }
        }
        return res;
    }
};